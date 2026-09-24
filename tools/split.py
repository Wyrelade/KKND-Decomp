#!/usr/bin/env python3
"""Split KKND.EXE's code object into one assembly listing per function (the splat step).

Writes asm/DOS/nonmatchings/<name>.s for every function in configs/DOS/functions.csv, in
Intel syntax with symbolic operands: code targets become `func_XXXXXXXX` / local `.LXXXXXXXX`
labels, fixed-up data addresses become `D_XXXXXXXX`. Names come from configs/DOS/symbols.txt
(`name = 0xVA;`) when present. The listing is a *reading* aid and the m2c/diff input; the
build does not assemble it (unmatched functions keep their original bytes, see build_kknd.py).

A function whose C is already in src/ is still listed; the build is the judge of a match.

usage: split.py [KKND.EXE]
"""
import csv
import os
import re
import sys

import capstone
from capstone import x86 as cx

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def load_symbols():
    syms = {}
    p = os.path.join(ROOT, "configs", "DOS", "symbols.txt")
    if os.path.exists(p):
        for line in open(p, encoding="utf-8"):
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if m:
                syms[int(m.group(2), 16)] = m.group(1)
    return syms


def load_functions():
    rows = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["va"], 16), int(r["size"]), int(r["span"]), r["name"]))
    return rows


def main():
    exe = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE")
    le = LE(exe)
    img = le.load(relocate=True)
    code = le.objs[0]
    cbuf = img[code.index]
    fix_at = {f.src_va: f for f in le.fixups()}
    syms = load_symbols()
    funcs = load_functions()
    fnames = {va: syms.get(va, name) for va, _, _, name in funcs}

    def name_of(va):
        if va in fnames:
            return fnames[va]
        if va in syms:
            return syms[va]
        return "D_%08X" % va

    data = le.objs[2]
    dbuf = img[data.index]

    def string_at(va):
        """Printable NUL-terminated string at a data address (>= 3 chars), escaped, else None."""
        if not (data.base <= va < data.base + data.vsize):
            return None
        o = va - data.base
        end = dbuf.find(b"\x00", o, o + 200)
        if end < 0 or end - o < 3:
            return None
        raw = bytes(dbuf[o:end])
        if not all(32 <= c < 127 or c in (9, 10, 13) for c in raw):
            return None
        esc = {"\\": "\\\\", "\n": "\\n", "\r": "\\r", "\t": "\\t", '"': '\\"'}
        return "".join(esc.get(ch, ch) for ch in raw.decode("latin1"))[:80]

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    outdir = os.path.join(ROOT, "asm", "DOS", "nonmatchings")
    os.makedirs(outdir, exist_ok=True)
    hexre = re.compile(r"0x[0-9a-f]+")
    for va, size, span, _ in funcs:
        name = fnames[va]
        raw = bytes(cbuf[va - code.base: va - code.base + span])
        insns = list(md.disasm(raw[:size], va))
        # local branch targets
        labels = set()
        for i in insns:
            if cx.X86_GRP_JUMP in i.groups and i.operands and i.operands[0].type == cx.X86_OP_IMM:
                t = i.operands[0].imm
                if va <= t < va + span:
                    labels.add(t)
        lines = ["# %s  va 0x%08X  size %d (span %d)" % (name, va, size, span),
                 "glabel %s" % name]
        for i in insns:
            if i.address in labels and i.address != va:
                lines.append(".L%08X:" % i.address)
            ops = i.op_str
            reloc = [a for a in range(i.address, i.address + i.size) if a in fix_at]
            if cx.X86_GRP_JUMP in i.groups or cx.X86_GRP_CALL in i.groups:
                if i.operands and i.operands[0].type == cx.X86_OP_IMM:
                    t = i.operands[0].imm
                    ops = ".L%08X" % t if (va < t < va + span and t in labels) else name_of(t)
            if reloc:
                for a in reloc:
                    tv = fix_at[a].target_va
                    ops = hexre.sub(lambda m, tv=tv: name_of(tv) if int(m.group(), 16) == tv else m.group(), ops)
            note = ""
            for a in reloc:
                tv = fix_at[a].target_va
                st = string_at(tv)
                if st is not None:
                    note = '  ; "%s"' % st
            lines.append("    /* %06X %-20s */ %-7s %s%s" % (i.address, i.bytes.hex(), i.mnemonic, ops, note))
        tail = raw[size:]
        if tail:
            lines.append("    /* pad */ .byte " + ", ".join("0x%02X" % b for b in tail))
        with open(os.path.join(outdir, name + ".s"), "w", newline="\n") as fh:
            fh.write("\n".join(lines) + "\n")
    print("wrote %d functions to %s" % (len(funcs), os.path.relpath(outdir, ROOT)))


if __name__ == "__main__":
    main()
