#!/usr/bin/env python3
"""Build KKND.EXE from src/ and verify it is byte-identical to the retail executable.

Pipeline (the DW2 `build_dw2.py` equivalent for a Watcom / DOS4GW LE target):
  1. Parse dumps/disc/KKND/KKND.EXE (tools/le.py) into raw, unrelocated object images.
  2. Compile every src/**/*.c with wcc386 (flags: configs/DOS/cflags.txt, or a first-line
     `/* cflags: ... */` override in the file) into OMF objects.
  3. Every function defined in C is cut out of its object and checked against the original
     function at its address (configs/DOS/functions.csv + configs/DOS/symbols.txt):
       - every non-relocated byte must be identical, and the length must equal the original;
       - every relocation must resolve to the SAME target as the original: a `call rel32`
         to the same function, an absolute fixup to the same LE fixup target (+ addend).
     A function that fails is a build failure, exactly like a non-matching C function in the
     DW2 build. Functions still written as INCLUDE_ASM(...) keep the original bytes.
  4. The checked bytes are spliced into the code object, the LE file is rewritten from the
     object images, and its SHA-1 is compared with configs/DOS/KKND.EXE.sha1.

Success prints `build/DOS/KKND.EXE: OK`. Anything else is not done.

usage: build_kknd.py [-v] [--list build/DOS/matched.txt]
"""
import argparse
import glob
import hashlib
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE, SRC_OFF32  # noqa: E402
from omf import OMF  # noqa: E402
import match  # noqa: E402

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "DOS", "KKND.EXE")


def file_flags(path, default):
    with open(path, encoding="latin1") as f:
        first = f.readline()
    m = re.match(r"\s*/\*\s*cflags:\s*(.*?)\s*\*/", first)
    return m.group(1).split() if m else default


def c_name(pub):
    """OMF public -> our symbol name (Watcom: `func_` gets a trailing _, data a leading _)."""
    if pub.endswith("_"):
        return pub[:-1]
    if pub.startswith("_"):
        return pub[1:]
    return pub


def resolve(name, funcs, syms):
    n = c_name(name)
    if n in funcs:
        return funcs[n][0]
    if n in syms:
        return syms[n]
    m = re.match(r"(?:func|D|jtbl|sub)_([0-9A-Fa-f]{8})$", n)
    if m:
        return int(m.group(1), 16)
    return None


def load_symbols():
    syms = {}
    p = os.path.join(ROOT, "configs", "DOS", "symbols.txt")
    if os.path.exists(p):
        for line in open(p, encoding="utf-8"):
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if m:
                syms[m.group(1)] = int(m.group(2), 16)
    return syms


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-v", action="store_true")
    ap.add_argument("--list", default=os.path.join(ROOT, "build", "DOS", "matched.txt"))
    a = ap.parse_args()

    le = LE(match.EXE)
    raw = le.load(relocate=False)
    code = le.objs[0]
    fix_at = {f.src_va: f for f in le.fixups()}
    tgt = match.Target()
    funcs = match.symbol_map()          # name -> (va, size)
    syms = load_symbols()
    default = match.default_flags()

    srcs = sorted(glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True))
    matched, errors = [], []
    objdir = os.path.join(ROOT, "build", "DOS", "obj")
    os.makedirs(objdir, exist_ok=True)
    for src in srcs:
        rel = os.path.relpath(src, ROOT)
        text = open(src, encoding="latin1").read()
        if not re.search(r"^\s*[A-Za-z_][\w\s\*]*\b\w+\s*\([^;]*\)\s*\{", text, re.M):
            continue  # INCLUDE_ASM only: nothing to compile
        obj_path = os.path.join(objdir, rel.replace(os.sep, "_")[:-2] + ".obj")
        match.compile_c(src, file_flags(src, default), obj_path)
        obj = OMF(obj_path)
        for pub, si, off, size in obj.functions():
            name = c_name(pub)
            if name not in funcs:
                errors.append("%s: %s is not a known function (add it to configs/DOS/symbols.txt)"
                              % (rel, name))
                continue
            va, osize = funcs[name]
            ok, diff = match.compare(tgt, obj, name, va, osize, quiet=not a.v)
            if not ok:
                errors.append("%s: %s does not match (%d bytes differ)" % (rel, name, diff))
                continue
            # relocation targets must agree with the original
            bad = None
            # A switch table is emitted at the start of the function's own segment, before its
            # code, so the checked region starts at the previous public in the segment (or 0).
            lo = max([o + z for p2, s2, o, z in obj.functions() if s2 == si and o < off] + [0])
            for fx in obj.fixups:
                if fx.seg != si or not (lo <= fx.offset < off + size):
                    continue
                field = va + fx.offset - off
                addend = struct.unpack_from("<i", obj.data[si], fx.offset)[0]
                if fx.target_kind == "seg" and fx.target_index == si:
                    want, addend = va - off + addend, 0  # own segment: table or case label
                elif fx.target_kind != "ext":
                    bad = "local segment reference at +%#x (move data to an extern D_ symbol)" % (
                        fx.offset - off)
                    break
                else:
                    want = resolve(fx.target, funcs, syms)
                if want is None:
                    bad = "unknown symbol %s" % fx.target
                    break
                if fx.selfrel:
                    rel32 = struct.unpack_from("<i", tgt.bytes_at(field, 4))[0]
                    have = field + 4 + rel32
                    if have != want + addend:
                        bad = "call/jmp target %s (%#x) != original %#x" % (fx.target, want, have)
                        break
                else:
                    of = fix_at.get(field)
                    if of is None or of.kind != SRC_OFF32 or of.target_va != want + addend:
                        bad = "reference %s+%d (%#x) != original %s" % (
                            fx.target, addend, want + addend,
                            "%#x" % of.target_va if of else "no fixup")
                        break
            if bad:
                errors.append("%s: %s: %s" % (rel, name, bad))
                continue
            # splice: our bytes everywhere except under a relocation on either side. Relocated
            # fields were checked above to resolve to the original target, so the original
            # (link-time) value is the correct one to keep.
            ours = obj.data[si][lo:off + osize]
            ours_fix = set()
            for fx in obj.fixups:
                if fx.seg == si and lo <= fx.offset < off + size:
                    ours_fix.update(range(fx.offset - lo, fx.offset - lo + fx.size))
            buf = raw[code.index]
            base = va - (off - lo)
            if off > lo and tgt.bytes_at(base, off - lo) != bytes(ours[:off - lo]) and any(
                    base + k not in tgt.fix and k not in ours_fix for k in range(off - lo)
                    if tgt.bytes_at(base + k, 1)[0] != ours[k]):
                errors.append("%s: %s: leading table bytes differ" % (rel, name))
                continue
            for k in range(len(ours)):
                if base + k not in tgt.fix and k not in ours_fix:
                    buf[base - code.base + k] = ours[k]
            matched.append((va, name, rel))

    for e in errors:
        print("ERROR " + e)

    # rewrite the LE pages from the object images
    out = bytearray(le.data)
    for o in le.objs:
        buf = raw[o.index]
        for k in range(o.page_count):
            fo, ln, _ = le.pages[o.page_index - 1 + k]
            chunk = bytes(buf[k * le.page_size: k * le.page_size + ln])
            out[fo:fo + len(chunk)] = chunk
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    open(OUT, "wb").write(out)
    with open(a.list, "w", newline="\n") as f:
        for va, name, rel in sorted(matched):
            f.write("0x%08X %s %s\n" % (va, name, rel.replace(os.sep, "/")))

    sha = hashlib.sha1(out).hexdigest()
    want = open(os.path.join(ROOT, "configs", "DOS", "KKND.EXE.sha1")).read().split()[0]
    total = len(funcs) if not syms else len({v for v, _ in funcs.values()})
    print("matched %d / %d functions" % (len(matched), total))
    rel_out = os.path.relpath(OUT, ROOT).replace(os.sep, "/")
    if sha == want and not errors:
        print("%s: OK" % rel_out)
        return 0
    print("%s: FAILED (sha1 %s, %d errors)" % (rel_out, sha, len(errors)))
    return 1


if __name__ == "__main__":
    sys.exit(main())
