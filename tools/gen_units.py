#!/usr/bin/env python3
"""Generate the source-unit layout: configs/DOS/units.csv and one src/*.c per unit.

KKND.EXE still carries the names of its C modules in __FILE__ strings (assert/error calls).
tools/find_units.py-style evidence: every function that references "units.c" belongs to units.c.
Watcom links objects in command-line order, so module code is contiguous. A unit starts at the
first function that references its file name and runs up to the next unit's start ([H] — exact
boundaries between two anchors are refined as functions are matched).

Everything from the Watcom C runtime startup onward is libraries (Watcom clib, StratosWare
MemCheck, SciTech UniVBE / VBE-AF, HMI SOS) plus a few game leftovers; it goes to src/lib/.

With --write-src the src/ files are (re)created with one INCLUDE_ASM per function. It never
overwrites a src file that already exists unless --force is given.

usage: gen_units.py [--write-src] [--force]
"""
import argparse
import bisect
import csv
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIB_START = 0x000710B5  # Watcom clib startup ("startup" string); libraries from here on [H]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--write-src", action="store_true")
    ap.add_argument("--force", action="store_true")
    a = ap.parse_args()
    le = LE(os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE"))
    img = le.load(relocate=True)
    fns = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            fns.append((int(r["va"], 16), r["name"]))
    starts = [va for va, _ in fns]
    strs = {}
    for o in le.objs:
        for m in re.finditer(rb"([A-Za-z_][A-Za-z0-9_]*\.[cC])\x00", img[o.index]):
            strs[o.base + m.start()] = m.group(1).decode().lower()
    first = {}
    for fx in le.fixups():
        if fx.target_va in strs and le.obj_of_va(fx.src_va).index == 1 and fx.src_va < LIB_START:
            fva = starts[bisect.bisect(starts, fx.src_va) - 1]
            n = strs[fx.target_va]
            first[n] = min(first.get(n, fva), fva)
    units = sorted((va, n) for n, va in first.items())
    units[0] = (starts[0], units[0][1])  # code before the first anchor -> first module (main.c)
    units.append((LIB_START, "lib/libs.c"))
    with open(os.path.join(ROOT, "configs", "DOS", "units.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["start", "unit"])
        for va, n in units:
            w.writerow(["0x%08X" % va, n])
    print("%d units" % len(units))
    if not a.write_src:
        return
    ustarts = [va for va, _ in units]
    per = {}
    for va, name in fns:
        u = units[bisect.bisect(ustarts, va) - 1][1]
        per.setdefault(u, []).append(name)
    for u, names in per.items():
        path = os.path.join(ROOT, "src", u)
        if os.path.exists(path) and not a.force:
            continue
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", newline="\n") as f:
            f.write("/* %s: %d functions (unit boundaries [H], see configs/DOS/units.csv) */\n"
                    % (u, len(names)))
            f.write('#include "common.h"\n\n')
            for n in names:
                f.write('INCLUDE_ASM("asm/DOS/nonmatchings", %s);\n' % n)
    print("wrote %d src files" % len(per))


if __name__ == "__main__":
    main()
