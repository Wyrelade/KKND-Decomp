# KKND compiler pin — 2026-09-24

**Compiler (retail):** Watcom C/C++32. The linked runtime prints "WATCOM C/C++32 Run-Time
system. (c) Copyright by WATCOM International Corp. 1988-1994" (0x7B7A9) → Watcom **10.0 or
10.0a** [H] (10.5 would say 1995, 10.6 1996). The game was built `Feb 16 1997`, so the team
kept an older compiler (normal for a long project). The UniVBE library object carries its own
"Watcom C/C++386" string (a separate vendor build).

**Compiler (ours, session 2):** the patched Open Watcom 2.0 `wcc386` in `doc/compiler_patch.md`
(jump tables through `cs:`, Watcom 10 switch costs, no loop padding, no entry threading, bottom-test
loop entry). It is the default in `tools/match.py`. The notes below describe stock Open Watcom.

**Compiler (stock):** Open Watcom `wcc386` — 1.9 (default, `D:/programs/re/openwatcom/ow19`) and
2.0 (current snapshot) give identical output on every probe so far. Open Watcom descends from
Watcom 11.0c, so 10.x→11 codegen changes are the expected source of non-matches.

**Flags:** `configs/DOS/cflags.txt` = `-s -of+ -5r -omilert -zm -zp1`

| Flag | Why | Evidence |
|---|---|---|
| `-s` | no stack-overflow checks | retail prologues have no `push N; call __CHK` |
| `-of+` | stack frame on every function | leaf functions still `push ebp; mov ebp,esp` |
| `-5r` | register calling convention, Pentium target | `and eax,0xff` for `u8` (with `-3r`: `movzx`); `-4r` equal so far |
| `-omiler` | `-ox` **without `-ob`** | `-or` is required; Open Watcom's `-ob` moves an `if` body after the epilogue (`jne skip` → `je body … jmp back`), retail never does (3 probes); `m`,`i`,`l`,`e` not yet distinguished |
| `-ot` | favour time | argument load chains go straight into their argument registers, `%` uses `mov eax,edx; sar edx,31`, spills use `sub esp,4; mov [ebp-4],r`, `for` loops rotate (agents A/C/D, session 2); no earlier match lost |
| `-zm` | one segment per function | 16-byte zero fill between functions, no cross-function tail merge |
| `-zp1` | packed structures [H] | a dword read at `[eax+0x2F]` (func_0004C2D0); no code difference yet |

**Probe set (kickoff):**

| Function | Shape | Result |
|---|---|---|
| func_000100C0 | `void f(u8 c) { g(c); }` | OK (`-4r`/`-5r` only) |
| func_00012080 | `void f(void) { g(1); }` | OK |
| func_00012390 | wait for a counter change | OK (only with `-zm` in a multi-function file) |
| func_000121B0 | `for` + `if (i != K)` + call | FAIL: loop entry / branch layout (see learnings) |

**Grid searched:** `-3r/-4r/-5r/-6r` × `-ox, -obmilr, -obmr, -oilr, -od, -os, -ot, -oneatx,
-oaxt, -obr, -omr` (+ single letters for the loop). Best = `-5r -ox` / `-4r -ox`.

**Second probe set (13 struct/field functions):** `-ox` 10/14, `-omiler` 13/14. The one left
(func_00053700) and func_000121B0 are the same class: Open Watcom threads jumps on conditions
it can prove on loop entry and lays out loops differently from Watcom 10.x. No flag changes it.
Plan: a patched Open Watcom `wcc386` that disables that jump threading / uses the 10.x loop
layout (the DW2 "GCC-Enhanced" approach), see PLAN.md 1.7.

**Open:**
- `-4r` vs `-5r`: find a function whose scheduling differs.
- Char signedness default (`-j`?) and structure packing (`-zp1/-zp4`?) — not probed yet;
  pin on the first struct-heavy matches.
- Floating point: `-fpi87` / `-fp5`? KKND is mostly integer; pin when an FPU function comes up.
- A real Watcom 10.0a `wcc386` would resolve the loop-layout class; keep collecting such cases in
  `tools/difficult_functions` so their total size shows whether it is worth hunting.
