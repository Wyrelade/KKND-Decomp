#!/usr/bin/env python3
"""Propose C for trivial function families and keep only what the build verifies.

Families (all with the standard `-of+` frame `push ebp; mov ebp,esp … mov esp,ebp; pop ebp; ret`):
  ret_const   `xor eax,eax` / `mov eax, K`            ->  int f(void) { return K; }
  forward     `call X`                                 ->  void f(void) { X(); }
  forward_k   `mov eax, K; call X`                     ->  void f(void) { X(K); }

Forwarders are written with an old-style callee declaration (`void X();`): the wrapper passes
its own register arguments through untouched, which is exactly what the machine code does.
Each candidate is checked with tools/match.py logic in one scratch compile; only exact matches
are written into src/. Run tools/build_kknd.py afterwards (the gate) — this tool never skips it.

usage: auto_families.py [--dry-run] [--unit units.c]
"""
import argparse
import csv
import os
import re
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import match  # noqa: E402
from omf import OMF  # noqa: E402

ROOT = match.ROOT
PRO = [r"push\s+ebp", r"mov\s+ebp, esp"]
EPI = [r"mov\s+esp, ebp", r"pop\s+ebp", r"ret\s*"]


def body_of(name):
    p = os.path.join(ROOT, "asm", "DOS", "nonmatchings", name + ".s")
    if not os.path.exists(p):
        return None
    ins = []
    for line in open(p):
        m = re.match(r"\s*/\* [0-9A-F]{6} [0-9a-f]+\s*\*/ (.*)$", line)
        if m:
            ins.append(m.group(1).strip())
    if len(ins) < 5:
        return None
    if not all(re.fullmatch(p, i) for p, i in zip(PRO, ins[:2])):
        return None
    if not all(re.fullmatch(p, i) for p, i in zip(EPI, ins[-3:])):
        return None
    return ins[2:-3]


def propose(name, mid):
    if len(mid) == 1:
        m = re.fullmatch(r"xor\s+eax, eax", mid[0])
        if m:
            return "int %s(void)\n{\n    return 0;\n}\n" % name, None
        m = re.fullmatch(r"mov\s+eax, (0x[0-9a-f]+|\d+)", mid[0])
        if m:
            return "int %s(void)\n{\n    return %s;\n}\n" % (name, m.group(1)), None
        m = re.fullmatch(r"call\s+(func_[0-9A-F]{8})", mid[0])
        if m:
            return "void %s(void)\n{\n    %s();\n}\n" % (name, m.group(1)), m.group(1)
    if len(mid) == 2:
        k = re.fullmatch(r"mov\s+eax, (0x[0-9a-f]+|\d+)", mid[0])
        c = re.fullmatch(r"call\s+(func_[0-9A-F]{8})", mid[1])
        if k and c:
            return "void %s(void)\n{\n    %s(%s);\n}\n" % (name, c.group(1), k.group(1)), c.group(1)
        k = re.fullmatch(r"xor\s+eax, eax", mid[0])
        if k and c:
            return "void %s(void)\n{\n    %s(0);\n}\n" % (name, c.group(1)), c.group(1)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--unit")
    a = ap.parse_args()
    pending = {}
    for dp, _, files in os.walk(os.path.join(ROOT, "src")):
        for fn in files:
            if fn.endswith(".c"):
                p = os.path.join(dp, fn)
                for m in re.finditer(r'INCLUDE_ASM\([^,]+,\s*(\w+)\);', open(p).read()):
                    pending[m.group(1)] = p
    cands = {}
    for name, path in pending.items():
        if a.unit and os.path.basename(path) != a.unit:
            continue
        mid = body_of(name)
        if mid is None:
            continue
        pr = propose(name, mid)
        if pr:
            cands[name] = (path,) + pr
    if not cands:
        print("no candidates")
        return
    # verify all candidates in one compile
    callees = sorted({c for _, _, c in cands.values() if c})
    text = '#include "common.h"\n' + "".join("void %s();\n" % c for c in callees) + "\n"
    text += "\n".join(code for _, code, _ in cands.values())
    tgt = match.Target()
    syms = match.symbol_map()
    with tempfile.TemporaryDirectory() as td:
        src = os.path.join(td, "autofam.c")
        open(src, "w").write(text)
        objp = os.path.join(td, "autofam.obj")
        match.compile_c(src, match.default_flags(), objp)
        obj = OMF(objp)
    ok = []
    for pub, si, off, size in obj.functions():
        name = pub.rstrip("_")
        if name in cands and name in syms:
            va, osz = syms[name]
            if match.compare(tgt, obj, name, va, osz, quiet=True)[0]:
                ok.append(name)
    print("%d candidates, %d match" % (len(cands), len(ok)))
    if a.dry_run:
        return
    by_file = {}
    for n in ok:
        by_file.setdefault(cands[n][0], []).append(n)
    for path, names in by_file.items():
        s = open(path).read()
        need = set()
        for n in names:
            _, code, callee = cands[n]
            s = s.replace('INCLUDE_ASM("asm/DOS/nonmatchings", %s);\n' % n, code + "\n")
            if callee:
                need.add(callee)
        decls = "".join("void %s();\n" % c for c in sorted(need)
                        if not re.search(r"\b%s\s*\(" % c, s.split("\n\n", 1)[0])
                        and not re.search(r"^\w[^\n;]*\b%s\s*\([^;]*\)\s*;" % c, s, re.M))
        if decls:
            s = s.replace('#include "common.h"\n', '#include "common.h"\n' + decls, 1)
        s = re.sub(r"\n{3,}", "\n\n", s)
        open(path, "w", newline="\n").write(s)
    print("landed %d functions in %d files" % (len(ok), len(by_file)))


if __name__ == "__main__":
    main()
