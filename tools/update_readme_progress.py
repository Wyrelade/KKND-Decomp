#!/usr/bin/env python3
"""Regenerate the README progress badge and table from PROGRESS.md.

PROGRESS.md is the single source of truth. Its header lines
    **Main exe functions identified: 3713 · matched: 3 (0.08%)** ...
    **Game code: 3/2006 · Libraries: 0/1707**
give the counts. This script recomputes the percentages, draws the bars, and rewrites the
marked regions in README.md so the two files never drift. Run it after bumping the matched
count in PROGRESS.md.

--sync first recounts the matched functions from src/ (same rule as tools/make_report.py: a
function defined in C is matched, because the build refuses non-matching C) and rewrites the two
PROGRESS.md lines, then updates the README.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROGRESS = os.path.join(ROOT, "PROGRESS.md")
README = os.path.join(ROOT, "README.md")

BAR_SEGMENTS = 20


def read_counts():
    with open(PROGRESS, encoding="utf-8") as f:
        text = f.read()
    m = re.search(r"functions identified:\s*(\d+)\s*.\s*matched:\s*(\d+)", text)
    g = re.search(r"Game code:\s*(\d+)/(\d+)\s*.\s*Libraries:\s*(\d+)/(\d+)", text)
    if not m or not g:
        sys.exit("could not find the progress lines in PROGRESS.md")
    return int(m.group(1)), int(m.group(2)), tuple(int(x) for x in g.groups())


def sync():
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import bisect
    import make_report as mr
    funcs, units, syms = mr.load()
    matched = mr.matched_vas(funcs, syms)
    lib_start = min(va for va, u in units if u.startswith("lib/"))
    game = [va for va, _, _ in funcs if va < lib_start]
    lib = [va for va, _, _ in funcs if va >= lib_start]
    gm = sum(1 for va in game if va in matched)
    lm = sum(1 for va in lib if va in matched)
    total, n = len(funcs), len(matched)
    with open(PROGRESS, encoding="utf-8") as f:
        text = f.read()
    text = re.sub(r"functions identified:\s*\d+\s*.\s*matched:\s*\d+\s*\([\d.]+%\)",
                  "functions identified: %d · matched: %d (%.2f%%)" % (total, n, 100.0 * n / total),
                  text)
    text = re.sub(r"Game code:\s*\d+/\d+\s*.\s*Libraries:\s*\d+/\d+",
                  "Game code: %d/%d · Libraries: %d/%d" % (gm, len(game), lm, len(lib)), text)
    with open(PROGRESS, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)


def bar(pct):
    filled = int(round(pct / 100.0 * BAR_SEGMENTS))
    filled = max(0, min(BAR_SEGMENTS, filled))
    return "▰" * filled + "▱" * (BAR_SEGMENTS - filled)


def replace_region(text, tag, body):
    pat = re.compile(r"<!-- %s -->.*?<!-- /%s -->" % (tag, tag), re.DOTALL)
    repl = "<!-- %s -->\n%s\n<!-- /%s -->" % (tag, body, tag)
    if not pat.search(text):
        sys.exit("marker %s not found in README.md" % tag)
    return pat.sub(lambda _: repl, text)


def main():
    if "--sync" in sys.argv:
        sync()
    total, matched, (gm, gt, lm, lt) = read_counts()
    pct = lambda a, b: 100.0 * a / b if b else 0.0
    p, pg, pl = pct(matched, total), pct(gm, gt), pct(lm, lt)
    badge = (
        "![matched](https://img.shields.io/badge/matched-"
        "%d%%2F%d%%20(%s)-1f6feb)" % (matched, total, ("%.2f%%" % p).replace("%", "%25"))
    )
    table = "\n".join([
        "| Component | Functions | Matched | Progress |",
        "|---|---:|---:|---|",
        "| **Main executable** (`KKND.EXE`) | %d | %d | `%s` %.2f%% |" % (total, matched, bar(p), p),
        "| &nbsp;&nbsp;└ Game code (`src/*.c`, 48 modules) | %d | %d | `%s` %.2f%% |"
        % (gt, gm, bar(pg), pg),
        "| &nbsp;&nbsp;└ Libraries (`src/lib/`) | %d | %d | `%s` %.2f%% |" % (lt, lm, bar(pl), pl),
    ])
    with open(README, encoding="utf-8") as f:
        text = f.read()
    text = replace_region(text, "PROGRESS:BADGE", badge)
    text = replace_region(text, "PROGRESS:TABLE", table)
    with open(README, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    print("README progress updated: %d/%d (%.2f%%)" % (matched, total, p))


if __name__ == "__main__":
    main()
