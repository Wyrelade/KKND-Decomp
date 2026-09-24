#!/usr/bin/env python3
"""Rank the easiest unmatched functions (still INCLUDE_ASM in src/).

Score = size in bytes, penalised for things that make a match harder under Watcom:
calls (argument setup / callee types), switch tables, FPU instructions, stack-passed args
(`ret N`), string/data references (need extern symbols) and far/interrupt frames. Functions
listed in tools/difficult_functions are skipped. Lower score = easier.

usage: score_functions.py [--unit units.c] [-n 40] [--game-only]
"""
import argparse
import csv
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--unit")
    ap.add_argument("-n", type=int, default=40)
    ap.add_argument("--game-only", action="store_true")
    a = ap.parse_args()
    pending = {}
    for dp, _, files in os.walk(os.path.join(ROOT, "src")):
        for fn in files:
            if fn.endswith(".c"):
                rel = os.path.relpath(os.path.join(dp, fn), os.path.join(ROOT, "src")).replace(os.sep, "/")
                for m in re.finditer(r"INCLUDE_ASM\([^,]+,\s*(\w+)\)", open(os.path.join(dp, fn)).read()):
                    pending[m.group(1)] = rel
    skip = set()
    p = os.path.join(ROOT, "tools", "difficult_functions")
    if os.path.exists(p):
        skip = {l.split()[0] for l in open(p) if l.strip() and not l.startswith("#")}
    rows = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            name = r["name"]
            unit = pending.get(name)
            if unit is None or name in skip:
                continue
            if a.unit and unit != a.unit:
                continue
            if a.game_only and unit.startswith("lib/"):
                continue
            s = os.path.join(ROOT, "asm", "DOS", "nonmatchings", name + ".s")
            if not os.path.exists(s):
                continue
            body = open(s).read()
            size = int(r["size"])
            calls = body.count(" call ")
            score = size + 12 * calls
            score += 80 * len(re.findall(r"cs:\[", body))
            score += 40 * len(re.findall(r"\bf[a-z]+ ", body))
            score += 30 * len(re.findall(r"\bD_[0-9A-F]{8}", body))
            if re.search(r"\bret\s+0x", body):
                score += 20
            if "retf" in body or "iretd" in body:
                score += 200
            if not body.split("\n")[2].strip().endswith("push    ebp"):
                score += 100  # no standard frame: data, thunk or hand-written asm
            rows.append((score, size, name, unit))
    rows.sort()
    for score, size, name, unit in rows[:a.n]:
        print("%6d  %5d  %-16s %s" % (score, size, name, unit))
    print("(%d unmatched candidates)" % len(rows))


if __name__ == "__main__":
    main()
