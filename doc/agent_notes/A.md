# Agent A notes (super.c, infantry.c, aircraft.c, tower.c, outpost.c, beastenc.c)

## KEY FINDING: add `-ot` to the flags (`-s -of+ -5r -omilert -zm -zp1`)

Problem: a whole family of functions (`func_0001A6A0(a->field_5C, a->field_18->field_3C,
D_000CD960[a->field_80])`, ~15 in my modules alone) differed only in register targeting: retail
loads the intermediate pointer straight into the destination argument register
(`mov edx,[eax+0x18]; mov ebx,[ebx*4+tbl]; mov edx,[edx+0x3c]; mov eax,[eax+0x5c]`), OW with
`-omiler` goes through EAX (`mov eax,[eax+0x18] ... mov edx,[eax+0x3c]; mov eax,[ecx+0x5c]`).
Fix: `-ot` (optimize for time). With `-omilert` all of func_00038850/38F90/38D50/386F0/38AB0/
391F0, func_0002D020, func_0003DEA0, func_000464B0/464F0/467B0/468D0, func_00046450 match.
Checked: every function already landed in ALL src files still matches with -ot (match.py over every
src/*.c, base vs -ot: no new FAIL; sound.c 4->0 and uncover.c 2->0 FAILs even improved).
Recommendation for the coordinator: put `-ot` in configs/DOS/cflags.txt. Until then my six files
carry the first-line override `/* cflags: -s -of+ -5r -omilert -zm -zp1 */`.

## Codegen findings

### Indirect call through a parameter/local: Watcom 10 keeps the pointer in memory -> `volatile`
Problem: `void f(int a, int b, int (*c)(), int d) { g(a, b, c(), d); }`.
Symptom: retail `mov [ebp-8], ebx; call dword ptr [ebp-8]` (with `sub esp,4`, a in esi);
OW keeps c in ebx (`call ebx`).
Fix: declare the pointer volatile: `int (*volatile c)()`. Same for a local fn pointer that is
assigned then called in a loop (`int (*volatile fp)(); fp = func_00038210; while (!g(a, K, fp(), 0));`,
func_00036A20). When register pressure already forces the spill (func_000381A0), plain works too.

### Parameter that retail spills and re-reads (`mov [ebp-x],edx; mov esi,[ebp-x]`): try `volatile`
func_000372F0: `volatile int n` reproduced the spill/re-read and `add edi,[ebp-x]` exactly
(remaining diff was only register choice of temporaries).

### Loops: retail rotates (guard + bottom test); write `if (guard) do {...} while (cond);`
OW keeps a `while`/`for` loop as top-test + `jmp` back; retail has `test; jle out` guard then
a bottom `cmp; jl top`. Writing the loop as `if (m > 0) do { ... } while (i < m);` gives the
retail block layout (func_000372F0, func_00032650).


### Callee-saved temp preference: Watcom 10 picks EBX first, Open Watcom picks ECX first (compiler class `rp`)
Seen on func_0002E940, func_0003B660, func_00046C70, func_000491E0, func_00047CE0 ... (most of my
near misses). Minimal: `void f(S *a) { s32 t = a->field_38; g(a->field_3C); g(t); h(a); }`
-> retail `push ebx; mov ebx,[eax+0x38] ... mov eax,ebx`, OW `push ecx; mov ecx,[eax+0x38] ... mov eax,ecx`.
With two temps retail gives the higher-priority one EBX and the next ECX; OW does the reverse.
No -o letter / -3r/-4r changes it. Needs the register preference order patched in wcc386
(OW cg `386rgtbl.c`-style tables). Worth doing: it blocks many small functions.

### Reusing a dead parameter variable makes OW coalesce into EAX (like retail)
func_0003C1B0: retail `mov eax,[eax+0x3c]; mov edx,[eax+0x20]; inc [edx+4]; call g` (eax reused).
`BeastState *s = a->field_3C; ...; g(s);` gives s in edx + `mov eax,edx`.
`a = (BeastObj *)a->field_3C; ((BeastState *)a)->field_20->field_4++; g(a);` matches.

### Two calls differing in one constant, in if/else: write both calls
func_00047E50: retail `cmp; jne; mov ebx,2; mov edx,0x4d0; jmp; L: mov ebx,2; mov edx,0x3c8; J: mov eax,[eax+0x5c]; call`.
A ternary argument gives a single `mov ebx,2`. `if (c) f(a->x, 0x4d0, 2); else f(a->x, 0x3c8, 2);`
matches (OW tail-merges the common suffix of the two calls, exactly like retail).

### Variadic callee: `void func_0001C9E0(void *, char *, ...);` gives `push str; push a; call; add esp,8`
(func_0003FBE0, a debug printf `"BlockedMode
"`).

## Hard / skipped functions

| function | attempts | best diff | reason |
|---|---|---|---|
| func_00032650 | 3 | 28 | retail `lea eax,[ebx+ecx+1]; je` uses imul flags (Watcom 10 peephole quirk) + regalloc |
| func_00038170 | 4 | 18 | regalloc: which of a/b/d goes to stack vs esi/edi |
| func_00034F30 | 4 | 7 | retail `cmp dword [mem],0`, OW loads into eax then `test` |
| func_00032510 | 2 | 14 | retail materializes constants 1/0 in ebx/edx before storing to globals |
| func_000327D0 | 2 | 38 | strlen-to-newline loop, retail rotated with `mov ch,[eax+1]` lookahead |
| func_00039360 | 2 | 12 | regalloc: retail uses edx for the global and keeps 0 in ebx across the call |
| func_00038850/38F90/38D50 | 2 | 3 | regalloc: temp for a->field_18 goes to edx in retail, eax in OW |
| func_000372F0 | 5 | 10 | only regalloc of loop temps (i edx, c bl, ctype cl) after volatile + do/while |
| func_00042FB0 | 1 | 66 | retail loads both operands into regs (ebx/ecx, edx/esi) before cmp; OW uses cmp reg,[mem] |
| func_00046450 | 3 | 10 | regalloc (retail temp ebx, OW edx) |
| func_00046C70 | 3 | 4 | regalloc (retail ebx/ecx swapped vs OW); needs `int r = s->field_10(s); ... return r;` |
| func_00039390 | 3 | 24 | goto-shaped loop gets block order right; OW hoists `lea edx,[ecx+0x14]` loop invariant |
| func_00033C30/33CA0 | 1 | 37/50 | spill slot assignment / scheduling |
| func_0002E940 | 2 | 4 | reg preference: retail picks ebx for a callee-saved temp, OW picks ecx (no flag changes it: -3r/-4r/-omile/-oilr tried) |
| func_0002D020 | 2 | 5 | same family as 38850: retail uses ebx/edx for arg temps, OW eax; real prototype does not help |
| func_000491E0 | 2 | 41 | retail reuses dead eax/ebx for chain temps; OW picks ecx/esi |
| func_000485E0 | 1 | 62 | retail `mov ebx,[edx+0x134]; test ebx,ebx` vs OW `cmp [mem],0`, plus ebx/ecx preference |
| func_0003B660 | 1 | 7 | rp (ebx/ecx swap) |
| func_0003AA30 | 2 | 32 | retail `imul eax,ebx` with counter in eax, p in edx; OW swaps roles |
| func_00047CE0/484D0 | 1 | 41 | rp + retail keeps a second copy of the new object in ebx |
| func_00035770/370C0/37340 | 4 | 3 instr | only scheduling: retail `mov dx,si` (u16 arg) before the `mov [eax+0x88],1` store; locals for the globals fixed the reload pattern |
| func_00039070 | 2 | 10 | arg evaluation order/scheduling (retail loads the 4th arg global first) |
| func_00036780/36710/36070/366A0 | 1 | 25 | infinite loop; retail keeps constant 0 in edi across loop (const-in-reg) + rp |
| func_00037810/00038050 | 0 | - | retail materializes store constants in callee-saved regs before a call (const-in-reg class, see 32510) |
| func_000464B0/3DEA0/464F0 | 1 | 3-12 | D_000CD960 family: retail loads the pointer for arg 2 directly into edx, OW into eax |
| func_00045BD0 | 1 | 81 | retail copies both params to edi/esi around a variadic (cdecl) call; OW assumes edx survives |
| func_00042A10/3F870/3F8E0 | 1 | 7-21 | retail loads stack (variadic) args into edx/ebx before `push`, OW into eax/edx; same eax-vs-edx preference as the D_000CD960 family |
| func_00047760 | 2 | 86 | retail splits byte RMW `and byte [eax+0x27],0xef` into load/and/store interleaved with arg setup (Pentium scheduling); bitfield did not help |
| func_00048C90 | 1 | 70 | multiply/neg expression scheduling |
| func_0003C7F0/3C890 | 0 | - | heavy interleaving of stores with variadic-call setup; skipped |
