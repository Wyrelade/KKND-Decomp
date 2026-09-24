#!/usr/bin/env python3
"""Compile one C file with wcc386 and diff each of its functions against KKND.EXE.

This is the per-function matching loop (the asm-differ / iso.py equivalent for Watcom):
  1. `wcc386 <flags> file.c` -> OMF object (tools/omf.py reads it)
  2. every public in _TEXT named `func_XXXXXXXX` / `func_XXXXXXXX_` (or a symbol from
     configs/DOS/symbols.txt) is cut out and compared to the original bytes at its VA
  3. bytes under a relocation on *either* side are masked; everything else must be identical,
     and the compiled length must equal the original function size.

Prints a side-by-side instruction diff for mismatches. Exit code 0 only if every function matches.

usage: match.py src/file.c [--flags "..."] [--func NAME] [-q]
"""
import argparse
import csv
import os
import re
import subprocess
import sys
import tempfile

import capstone

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE  # noqa: E402
from omf import OMF  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE")


def watcom_env():
    """Toolchain: $WATCOM, else tools/watcom, else the patched wcc386 (doc/compiler_patch.md),
    else stock Open Watcom 1.9."""
    wat = os.environ.get("WATCOM")
    if not wat:
        for cand in (os.path.join(ROOT, "tools", "watcom"), "D:/programs/re/openwatcom/patched",
                     "D:/programs/re/openwatcom/ow19"):
            if os.path.isdir(cand):
                wat = cand
                break
    wat = os.path.normpath(wat)
    env = dict(os.environ)
    env["WATCOM"] = wat
    env["INCLUDE"] = os.path.join(wat, "h")
    if os.name == "nt":
        bindir = next(b for b in ("binnt64", "binnt") if os.path.isdir(os.path.join(wat, b)))
        exe = "wcc386.exe"
    else:
        bindir = next(b for b in ("binl64", "binl") if os.path.isdir(os.path.join(wat, b)))
        exe = "wcc386"
    env["PATH"] = os.path.join(wat, bindir) + os.pathsep + env.get("PATH", "")
    return env, os.path.join(wat, bindir, exe)


def default_flags():
    p = os.path.join(ROOT, "configs", "DOS", "cflags.txt")
    if os.path.exists(p):
        return open(p).read().split()
    return []


def compile_c(src, flags, obj):
    """Compile `src` to OMF `obj`. wcc386 splits arguments on spaces even when quoted and old
    versions read '/' as an option switch, so compile from build/tmp with relative, backslashed
    paths (the source is copied there; #include "..." resolves through -i=include)."""
    import shutil
    env, cc = watcom_env()
    tag = "p%d" % os.getpid()  # per-process dir: parallel matchers must not share scratch files
    tmp = os.path.join(ROOT, "build", "tmp", tag)
    os.makedirs(tmp, exist_ok=True)
    base = os.path.splitext(os.path.basename(src))[0]
    shutil.copyfile(src, os.path.join(tmp, base + ".c"))
    sep = "\\" if os.name == "nt" else "/"
    rel = "build" + sep + "tmp" + sep + tag + sep + base
    cmd = [cc, "-q", "-zq"] + flags + ["-i=include", "-i=src", "-fo=" + rel + ".obj", rel + ".c"]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=ROOT)
    out = os.path.join(tmp, base + ".obj")
    if r.returncode != 0 or not os.path.exists(out):
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit("compile failed")
    shutil.move(out, obj)
    shutil.rmtree(tmp, ignore_errors=True)


def symbol_map():
    m = {}
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            m[r["name"]] = (int(r["va"], 16), int(r["size"]))
    p = os.path.join(ROOT, "configs", "DOS", "symbols.txt")
    if os.path.exists(p):
        sizes = {va: sz for va, sz in m.values()}
        for line in open(p, encoding="utf-8"):
            mm = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if mm:
                va = int(mm.group(2), 16)
                if va in sizes:
                    m[mm.group(1)] = (va, sizes[va])
    return m


class Target:
    def __init__(self):
        self.le = LE(EXE)
        self.raw = self.le.load(relocate=False)
        self.code = self.le.objs[0]
        self.fix = set()
        for f in self.le.fixups():
            for k in range(f.size):
                self.fix.add(f.src_va + k)

    def bytes_at(self, va, n):
        o = self.code
        return bytes(self.raw[o.index][va - o.base: va - o.base + n])


def compare(tgt, obj, name, va, size, quiet=False):
    """Return (ok, n_diff_bytes). Relocations masked both sides; call rel32 to ext masked too."""
    funcs = {n.rstrip("_"): (si, off, sz) for n, si, off, sz in obj.functions()}
    si, off, csz = funcs[name]
    ours = bytes(obj.data[si][off:off + csz])
    # trailing zero/nop padding in our segment belongs to alignment, not the function
    ours_trim = ours.rstrip(b"\x00") if len(ours) > size else ours
    mask = set()
    for f in obj.fixups:
        if f.seg == si and off <= f.offset < off + csz:
            for k in range(f.size):
                mask.add(f.offset - off + k)
    theirs = tgt.bytes_at(va, size)
    for k in range(size):
        if va + k in tgt.fix:
            mask.add(k)
    diff = 0
    n = max(len(ours_trim), size)
    for k in range(n):
        if k in mask:
            continue
        a = ours_trim[k] if k < len(ours_trim) else None
        b = theirs[k] if k < size else None
        if a != b:
            diff += 1
    ok = diff == 0 and len(ours_trim) == size
    if not ok and not quiet:
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        L = ["%-8x %-18s %s %s" % (i.address, i.bytes.hex(), i.mnemonic, i.op_str)
             for i in md.disasm(ours_trim, va)]
        R = ["%-8x %-18s %s %s" % (i.address, i.bytes.hex(), i.mnemonic, i.op_str)
             for i in md.disasm(theirs, va)]
        print("--- %s  ours %d bytes / target %d bytes, %d differing" % (name, len(ours_trim), size, diff))
        for k in range(max(len(L), len(R))):
            l = L[k] if k < len(L) else ""
            r = R[k] if k < len(R) else ""
            mark = "  " if l.split()[1:2] == r.split()[1:2] else "! "
            print("%s%-60s | %s" % (mark, l, r))
    return ok, diff


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--flags", default=None)
    ap.add_argument("--func", default=None)
    ap.add_argument("-q", action="store_true")
    a = ap.parse_args()
    flags = a.flags.split() if a.flags is not None else default_flags()
    syms = symbol_map()
    tgt = Target()
    with tempfile.TemporaryDirectory() as td:
        objp = os.path.join(td, "m.obj")
        compile_c(a.src, flags, objp)
        obj = OMF(objp)
    allok = True
    for n, _si, off, sz in obj.functions():
        name = n.rstrip("_")
        if a.func and name != a.func:
            continue
        if name not in syms:
            print("?? %s: not a known function name" % name)
            continue
        va, size = syms[name]
        ok, diff = compare(tgt, obj, name, va, size, a.q)
        print("%s %s" % ("OK  " if ok else "FAIL", name))
        allok &= ok
    sys.exit(0 if allok else 1)


if __name__ == "__main__":
    main()
