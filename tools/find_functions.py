#!/usr/bin/env python3
"""Discover every function in KKND.EXE's 32-bit code object and write configs/DOS/functions.csv.

Method (recursive descent, Watcom-aware):
  seeds  = LE entry point
         + every fixup target in the code object whose fixup *source* is in a data object
           (function-pointer tables, callbacks)
         + every fixup target used as an instruction immediate (`push offset f`, `mov eax, offset f`)
  walk   = capstone x86-32 per function: follow jcc/jmp inside the function, `call rel32`
           seeds a new function, `jmp [reg*4 + table]` reads its table through the fixups at
           consecutive addresses (Watcom switch tables live in the code object).
  gaps   = anything left undecoded that starts with a plausible prologue and is itself not a
           fixup source (table) is seeded and walked, repeated until nothing new appears.

A function's size is the distance to the next function start, minus trailing alignment padding
(`nop`, `mov eax,eax` style fill or zero bytes). Data blocks inside the code object
(switch tables, strings) are written to configs/DOS/code_data.csv.

usage: find_functions.py [KKND.EXE]
"""
import csv
import os
import sys

import capstone
from capstone import x86 as cx

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE, SRC_OFF32  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    exe = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE")
    le = LE(exe)
    img = le.load(relocate=True)
    code = le.objs[0]
    cbuf = img[code.index]
    lo, hi = code.base, code.base + code.vsize
    fix = le.fixups()
    fix_at = {f.src_va: f for f in fix}
    # bytes covered by fixup fields
    fix_bytes = set()
    for f in fix:
        for k in range(f.size):
            fix_bytes.add(f.src_va + k)

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True

    funcs = set([le.entry_va])
    for f in fix:
        if f.target_obj == code.index and f.kind == SRC_OFF32:
            src_obj = le.obj_of_va(f.src_va)
            if src_obj is not None and src_obj.index != code.index:
                funcs.add(f.target_va)

    covered = {}        # insn va -> length
    table_bytes = set()  # jump-table dwords inside code
    owner = {}          # insn va -> function va
    done = set()

    def rd(va, n):
        return bytes(cbuf[va - lo: va - lo + n])

    def walk(fva):
        work = [fva]
        seen = set()
        while work:
            va = work.pop()
            while lo <= va < hi and va not in seen:
                if va in covered and owner.get(va) != fva:
                    break  # ran into another function's code
                seen.add(va)
                ins = next(md.disasm(rd(va, 16), va), None)
                if ins is None:
                    break
                covered[va] = ins.size
                owner.setdefault(va, fva)
                g = ins.groups
                m = ins.mnemonic
                # immediates that carry a fixup to code = function pointers
                for k in range(ins.size - 3):
                    ff = fix_at.get(va + k)
                    if ff and ff.target_obj == code.index and not m.startswith("j"):
                        funcs.add(ff.target_va)
                if cx.X86_GRP_CALL in g:
                    op = ins.operands[0]
                    if op.type == cx.X86_OP_IMM and lo <= op.imm < hi:
                        funcs.add(op.imm)
                elif cx.X86_GRP_JUMP in g:
                    op = ins.operands[0]
                    if op.type == cx.X86_OP_IMM:
                        if lo <= op.imm < hi:
                            work.append(op.imm)
                        if m == "jmp":
                            break
                    elif op.type == cx.X86_OP_MEM:
                        # switch: jmp [reg*4 + table]
                        t = op.mem.disp
                        if op.mem.scale == 4 and lo <= t < hi:
                            p = t
                            while p in fix_at and fix_at[p].target_obj == code.index:
                                tgt = fix_at[p].target_va
                                for k in range(4):
                                    table_bytes.add(p + k)
                                work.append(tgt)
                                p += 4
                        break
                    else:
                        break
                elif cx.X86_GRP_RET in g or cx.X86_GRP_IRET in g or m in ("hlt", "int3", "ud2"):
                    break
                va += ins.size

    PROLOGUE = (b"\x53", b"\x51", b"\x52", b"\x55", b"\x56", b"\x57", b"\x68", b"\x83\xec", b"\x81\xec",
                b"\x8b\xc0", b"\xb8", b"\x60", b"\x1e", b"\x06")
    while True:
        pending = sorted(funcs - done)
        if not pending:
            # gap fill
            starts = sorted(funcs)
            new = set()
            va = lo
            while va < hi:
                if va in covered:
                    va += covered[va]
                    continue
                b = cbuf[va - lo]
                if b in (0x00, 0x90, 0xCC) or va in fix_bytes or va in table_bytes:
                    va += 1
                    continue
                if any(rd(va, len(p)) == p for p in PROLOGUE):
                    new.add(va)
                    # skip to next covered byte
                    while va < hi and va not in covered:
                        va += 1
                    continue
                va += 1
            new -= funcs
            if not new:
                break
            funcs |= new
            continue
        for fva in pending:
            done.add(fva)
            if lo <= fva < hi:
                walk(fva)

    funcs = sorted(f for f in funcs if lo <= f < hi)
    rows = []
    for i, f in enumerate(funcs):
        end = funcs[i + 1] if i + 1 < len(funcs) else hi
        # last decoded instruction owned by f before end
        last = f
        va = f
        while va < end and va in covered:
            last = va + covered[va]
            va = last
        # extend over owned code reached by jumps further down (non-contiguous blocks)
        for a in range(va, end):
            if a in covered and owner.get(a) == f:
                last = max(last, a + covered[a])
        rows.append((f, max(last, f + 1) - f, end - f))

    os.makedirs(os.path.join(ROOT, "configs", "DOS"), exist_ok=True)
    out = os.path.join(ROOT, "configs", "DOS", "functions.csv")
    with open(out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["va", "size", "span", "name"])
        for f, size, span in rows:
            w.writerow(["0x%08X" % f, size, span, "func_%08X" % f])
    # code-object data (switch tables)
    tabs = sorted(table_bytes)
    blocks = []
    for a in tabs:
        if blocks and a == blocks[-1][1]:
            blocks[-1][1] = a + 1
        else:
            blocks.append([a, a + 1])
    with open(os.path.join(ROOT, "configs", "DOS", "code_data.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["va", "size", "kind"])
        for a, b in blocks:
            w.writerow(["0x%08X" % a, b - a, "jumptable"])
    cov = sum(covered.values())
    print("functions: %d  decoded bytes: %d / %d (%.1f%%)  jump tables: %d" %
          (len(rows), cov, code.vsize, 100.0 * cov / code.vsize, len(blocks)))


if __name__ == "__main__":
    main()
