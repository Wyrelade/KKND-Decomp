#!/usr/bin/env python3
"""Build an objdiff-format progress report (report.json, version 2) for decomp.dev.

No game data needed: the report is derived from committed files only.
  configs/DOS/functions.csv  every function in KKND.EXE's code object (VA + size)
  configs/DOS/units.csv      source unit (C module) address ranges
  configs/DOS/symbols.txt    real names for identified functions
  src/**/*.c                 a function *defined* in C (not INCLUDE_ASM) is matched: the build
                             gate (tools/build_kknd.py) refuses any C that is not byte-identical,
                             so a C body in main is by construction a verified match.

Measures map 1:1 onto objdiff's: matched_code / matched_functions (fuzzy 100%) for matched C,
complete_code for the same set (every matched function is byte-identical in the relinked exe).
One report unit per source file; categories `game` (Beam Software code) and `lib` (Watcom clib,
MemCheck, UniVBE, HMI SOS).

usage: make_report.py [out.json]      (also prints the counts used by PROGRESS.md)
"""
import bisect
import csv
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT_VERSION = 2
DEF_RE = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\([^;{}]*\)\s*(?:\n[^{;]*;)*\s*\{", re.M)


def load():
    funcs = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["va"], 16), int(r["size"]), r["name"]))
    units = []
    with open(os.path.join(ROOT, "configs", "DOS", "units.csv"), newline="") as f:
        for r in csv.DictReader(f):
            units.append((int(r["start"], 16), r["unit"]))
    syms = {}
    p = os.path.join(ROOT, "configs", "DOS", "symbols.txt")
    if os.path.exists(p):
        for line in open(p, encoding="utf-8"):
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if m:
                syms[m.group(1)] = int(m.group(2), 16)
    return funcs, units, syms


def matched_vas(funcs, syms):
    by_name = {n: va for va, _, n in funcs}
    by_name.update(syms)
    out = {}
    for dp, _, files in os.walk(os.path.join(ROOT, "src")):
        for fn in files:
            if not fn.endswith(".c"):
                continue
            text = open(os.path.join(dp, fn), encoding="latin1").read()
            text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
            for m in DEF_RE.finditer(text):
                name = m.group(1)
                if name in by_name:
                    out[by_name[name]] = name
    return out


def measures(items, matched):
    total = sum(s for _, s, _ in items)
    m_code = sum(s for va, s, _ in items if va in matched)
    m_funcs = sum(1 for va, _, _ in items if va in matched)
    pct = lambda a, b: (100.0 * a / b) if b else 0.0
    return {
        "fuzzy_match_percent": pct(m_code, total),
        "total_code": str(total),
        "matched_code": str(m_code),
        "matched_code_percent": pct(m_code, total),
        "total_functions": len(items),
        "matched_functions": m_funcs,
        "matched_functions_percent": pct(m_funcs, len(items)),
        "complete_code": str(m_code),
        "complete_code_percent": pct(m_code, total),
        "total_units": 1,
        "complete_units": 1 if items and m_funcs == len(items) else 0,
    }


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build", "DOS", "report.json")
    funcs, units, syms = load()
    names = {va: n for n, va in syms.items()}
    matched = matched_vas(funcs, syms)
    ustarts = [va for va, _ in units]
    per_unit = {}
    for va, size, name in funcs:
        u = units[bisect.bisect(ustarts, va) - 1][1]
        per_unit.setdefault(u, []).append((va, size, names.get(va, name)))
    report_units = []
    for u, items in per_unit.items():
        cat = "lib" if u.startswith("lib/") else "game"
        m = measures(items, matched)
        report_units.append({
            "name": "kknd/" + u[:-2],
            "measures": m,
            "functions": [{
                "name": n,
                "size": str(s),
                "fuzzy_match_percent": 100.0 if va in matched else 0.0,
                "address": str(va),
                "metadata": {"virtual_address": str(va)},
            } for va, s, n in items],
            "metadata": {"complete": m["complete_units"] == 1, "module_name": "KKND.EXE",
                         "source_path": "src/" + u, "progress_categories": [cat]},
        })
    all_m = measures(funcs, matched)
    all_m["total_units"] = len(report_units)
    all_m["complete_units"] = sum(1 for r in report_units if r["metadata"]["complete"])
    cats = []
    for cid, cname in (("game", "Game code"), ("lib", "Libraries")):
        items = [(va, s, n) for u, it in per_unit.items() for (va, s, n) in it
                 if ("lib" if u.startswith("lib/") else "game") == cid]
        cats.append({"id": cid, "name": cname, "measures": measures(items, matched)})
    report = {"measures": all_m, "units": report_units, "version": REPORT_VERSION,
              "categories": cats}
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    with open(out, "w") as f:
        json.dump(report, f, indent=1)
    g = cats[0]["measures"]
    print("%d functions, matched %d (%.2f%% of code); game %d/%d -> %s" % (
        len(funcs), len(matched), all_m["matched_code_percent"], g["matched_functions"],
        g["total_functions"], os.path.relpath(out, ROOT)))


if __name__ == "__main__":
    main()
