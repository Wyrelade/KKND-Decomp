#!/usr/bin/env python3
"""Replace `INCLUDE_ASM(..., <func>);` in a src file with matched C from a snippet file.

usage: land.py <src/module.c> <func> <snippet.c> [--decls <decls.c>]
The snippet is the function definition (plus any file-local helpers). --decls text is
inserted after the `/* decls */` marker (or after the last #include) once per line, skipping
lines already present. Run tools/build_kknd.py afterwards: only `OK` counts.
"""
import argparse
import re


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("func")
    ap.add_argument("snippet")
    ap.add_argument("--decls")
    a = ap.parse_args()
    text = open(a.src, encoding="latin1").read()
    pat = re.compile(r'^INCLUDE_ASM\("[^"]*",\s*%s\);\n' % re.escape(a.func), re.M)
    if not pat.search(text):
        raise SystemExit("%s: no INCLUDE_ASM for %s" % (a.src, a.func))
    code = open(a.snippet, encoding="latin1").read().strip("\n") + "\n"
    text = pat.sub(lambda m: code, text, count=1)
    if a.decls:
        have = set(text.splitlines())
        new = [l for l in open(a.decls, encoding="latin1").read().splitlines()
               if l.strip() and l not in have]
        if new:
            m = re.search(r"^/\* decls \*/\n", text, re.M)
            if not m:
                incs = list(re.finditer(r"^#include .*\n", text, re.M))
                pos = incs[-1].end() if incs else 0
                text = text[:pos] + "/* decls */\n" + text[pos:]
                m = re.search(r"^/\* decls \*/\n", text, re.M)
            text = text[:m.end()] + "\n".join(new) + "\n" + text[m.end():]
    open(a.src, "w", encoding="latin1", newline="\n").write(text)


if __name__ == "__main__":
    main()
