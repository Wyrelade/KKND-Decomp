#!/usr/bin/env python3
"""Harvest real function names from KKND's own diagnostic strings.

Beam's error messages name the function they are printed from: "MIPX_Hangup(): link %d: no free
events", "tLoadGameState(): produce unit has no building info". A string of the form
`Name(): …` or `Name: …` referenced by exactly one function is strong evidence that the function
IS `Name` [H until confirmed by reading the code]. `Name() failed` means the function *called*
Name and is recorded as a caller hint instead.

Writes configs/DOS/name_evidence.csv (va, func, candidate, kind, string). Review before copying a
name into configs/DOS/symbols.txt.

usage: name_evidence.py
"""
import bisect
import csv
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SELF = re.compile(rb"^([A-Za-z_][A-Za-z0-9_]{2,})\(\)\s*[:\-]")
CALLS = re.compile(rb"^([A-Za-z_][A-Za-z0-9_]{2,})\([^)]*\)\s+(failed|error|returned)", re.I)


def main():
    le = LE(os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE"))
    img = le.load(relocate=True)
    data = le.objs[2]
    dbuf = bytes(img[data.index])
    fns = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            fns.append((int(r["va"], 16), r["name"]))
    starts = [v for v, _ in fns]
    refs = {}
    for fx in le.fixups():
        if fx.target_obj == data.index and le.obj_of_va(fx.src_va).index == 1:
            refs.setdefault(fx.target_va, set()).add(fns[bisect.bisect(starts, fx.src_va) - 1])
    rows = []
    for tva, users in refs.items():
        o = tva - data.base
        end = dbuf.find(b"\x00", o, o + 200)
        if end < 0:
            continue
        s = dbuf[o:end]
        for rx, kind in ((SELF, "self"), (CALLS, "calls")):
            m = rx.match(s)
            if m and (kind == "calls" or len(users) == 1):
                for va, name in sorted(users):
                    rows.append((va, name, m.group(1).decode(), kind, s.decode("latin1")[:70]))
    rows = sorted(set(rows))
    out = os.path.join(ROOT, "configs", "DOS", "name_evidence.csv")
    with open(out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["va", "func", "candidate", "kind", "string"])
        for va, name, cand, kind, s in rows:
            w.writerow(["0x%08X" % va, name, cand, kind, s])
    print("%d self-name hints, %d caller hints -> %s" % (
        sum(1 for r in rows if r[3] == "self"), sum(1 for r in rows if r[3] == "calls"),
        os.path.relpath(out, ROOT)))


if __name__ == "__main__":
    main()
