# Decompilation Learnings

Notes on the Watcom C 32-bit toolchain (`wcc386 -s -of+ -5r -omilert -zm -zp1`, register calling
convention) used by this project. Each entry was verified against real target machine code.
Append new entries at the top. Search with `python tools/learn.py <terms>`.

## Session 2 agent batch: source tricks that fixed register choice and order (agents B, C, D).

Found 2026-09-24 (session 2), with the patched compiler. Problem -> symptom -> fix:
- Trace helper `func_00014D18(int line, char *file)`: stack args pushed in the wrong order still
  pass `match.py` (both immediates are under relocation masks). Only the build catches it. Needs
  `#pragma aux func_00014D18 parm routine [] modify [eax ebx ecx edx]`; sprintf helper
  `func_00014D9B` needs `modify [eax ebx ecx edx]`.
- Retail sets EBX/ECX for a later call before an earlier call: `#pragma aux <earlier callee>
  modify exact [eax]` in the caller's file (func_0004F670, func_00030C60).
- Global read then reused: load it into a local first; declaration order picks the load order
  (func_00050DB0). Load into a local before an intervening store also fixes some `fold` misses
  (func_0005E9C0, func_00070C30), not when the value is used at once (`inc [mem]`, `sub r,[mem]`).
- Two registers holding one pointer: two C variables, `T *e = f(); T *ev = e;` (func_0005E9C0).
- A store retail emits after the argument setup: comma expression in the first argument,
  `f((s->x = 0xFF, s), ...)` (func_0002CC20).
- Shared exit: assign the result in if/else and return once; an early `return 0` flips branch
  order. An OR chain of `==` comes out inverted: write an AND chain of `!=` with an else.
- `if ((r = f()) == 0 && (r = g()) == 0) return r; return 1;` for "return the zero result".
- An address constant passed as a call argument goes through a register in retail: assign it to a
  local just before the call.
- Inlined lookup: a local `u32 i` with if/else matches where a ternary does not (func_000264E0).
- Volatile spills: declaration order picks the stack slot, statement order the store order.
- Inline pragmas with Watcom 10 encodings for strlen (`29 c9`/`31 c0`) and port I/O
  (`include/serial.h`, func_0005E1D0/5E200).
- Open (compiler): compare-only temps avoid EAX in retail (EDX/EBX/ECX; func_0004E7D0 2 bytes,
  func_000585C0); binary-search switches use signed compares when a case is negative
  (func_0002F970); retail never does read-modify-write with a register operand on a stack slot
  (`inc [ebp-x]`); func_00029940 matches only with `KKND_ECXFIRST=1`, so allocation priority, not
  only the table order, differs. A global register-order change (KKND_REGORDER experiment) lost
  57-150 matches for every order tried; keep EAX,EDX,EBX,ECX,ESI,EDI.
- Frameless 16-aligned functions (func_0004D920, func_0004DA90, func_00014980, atoi/strcmp copies
  func_0004B510/func_0004B270) share files with framed ones: needs per-function flags in the build.
- Near-miss attempts (<= 40 bytes) are kept in `doc/nearmiss/<func>.c` to score compiler patches.

## `rp` and `mul` are compiler differences, now patched: EBX before ECX, shift/add multiplies (session 2).

Found 2026-09-24 (session 2). Problem: the two biggest near-miss classes from the agents. Symptom:
retail `push ebx; mov ebx,[eax+0x38]` where OW took ECX; retail `lea edx,[ecx*8]; sub edx,ecx;
shl edx,3` where OW emitted `imul edx,ecx,0x38`. Cause: OW's 32-bit register table lists ECX
before EBX (Watcom 10 had EBX first, like the 16-bit table), and OW's multiply cost for `-5r` is a
flat 6 (Pentium), which beats most shift/add sequences. Fix: patched `DoubleRegs[]` order,
`MulCost()` uses the 386/486 early-out estimate, and `Factor()` applies the trailing power of two
last. func_0002E940 matches as plain C. Functions tagged `rp`/`mul` in `tools/difficult_functions`
are worth a retry.

## The patched `wcc386` is the default: switch tables, no loop padding, no entry threading (session 2).

Found 2026-09-24 (session 2), details in `doc/compiler_patch.md`. Four Watcom 10.x behaviours are
now baked into the patched Open Watcom code generator, and the build stays OK with it:
- Switch jump tables are read with a `cs:` prefix, the size/time floor of the switch cost is 15
  (not 25), and a 3-case node uses a pure binary search. func_000323B0 (4 cases over 0..11) and
  func_0001CDC4 (nested switch) now match. For a switch where one case falls through into the
  next, write the source in the retail block order: `case 0x200: switch (b) {...} case 0x80:
  return 0x1000;` (the inner default falls into the outer case).
- No alignment padding: `-ot` padded loop heads and the code after a jump table with `lea` NOPs.
- No threading of a condition known on loop entry: `for (i = 0; i < 0xC4; i++) if (i != 0x54)
  f(i);` (func_000121B0) now matches as written.
- A single-exit loop is entered at its bottom test: `if (p) for (; n > 0; n--) *p++ = 0;`
  (func_00053700).
Problem to watch for: `tools/match.py` does not check where the code starts after a jump table,
only the build does (func_0001CDC4 said OK in match.py and failed the build until alignment was
off). Natural `for`/`while` loops now match where the old notes say to hand-rotate them into
`if (g) do {} while (c);`. Write the natural form first.

## Flags are now `-s -of+ -5r -omilert -zm -zp1`: `-ot` fixes argument set-up order (session 2).

Found by agents A, C and D independently (2026-09-24, part 2). Problem: calls whose arguments are
load chains. Symptom: retail loads each intermediate pointer straight into its destination
argument register (`mov edx,[eax+0x18]; mov ebx,[ebx*4+tbl]; mov edx,[edx+0x3c]; mov eax,[eax+0x5c]`),
`-omiler` builds everything in EAX first. `-ot` also gives retail's `mov eax,edx; sar edx,0x1f; idiv`
for `%` (not `cdq`), `sub esp,4; mov [ebp-4],edx` spills (not `push edx`) and rotated `for` loops
with a count in EAX. Fix: `t` in cflags.txt; every earlier match still builds OK and the 28
per-file overrides were removed. Watch out: `tools/match.py` ignores per-file `/* cflags */` lines.

## Watcom 10.x vs Open Watcom: the recurring non-matching classes (session 2, agents A-D).

Tags used in `tools/difficult_functions`. None has a source-level fix; all are candidates for the
patched compiler (PLAN 1.7). Skip them quickly and log them.

- `rp` / `rb` / `ra` register preference. Problem: a callee-saved temp or a value that survives a
  call. Symptom: retail `push ebx; mov ebx,[eax+0x38] ... mov eax,ebx`, OW the same with ECX. With
  two temps retail gives the first EBX and the next ECX; OW the reverse. Also retail prefers EDX
  where OW uses EAX for an argument temp. No `-o` letter or `-3r/-4r` changes it. The biggest class
  (dozens of 3-7 byte near misses: func_0002E940, func_00046C70, func_0001A9F0, func_00026620 ...).
- `mul` constant multiply. Symptom: retail strength-reduces (`mov edx,eax; shl eax,2; sub eax,edx;
  shl eax,3; add eax,edx` for *100, `lea edx,[ecx*8]; sub edx,ecx; shl edx,3` for *56); OW 1.9
  always emits `imul reg,reg,K`. Blocks every array of odd-size structs (func_0001E0E0, func_000142D0).
- `ci` constants via registers. Symptom: retail `mov ebx,1; xor edx,edx; mov [A],ebx; mov [B],edx`
  (and `push edx; xor edx,edx; mov [G],edx; pop edx` for a single `G = 0`), OW `mov dword [A],1` /
  `xor eax,eax; mov [G],eax`. Retail then reuses the zero register as a later call argument.
- `fold` memory operands. Symptom: retail `mov ebx,[eax]; sub edx,ebx`, `mov ah,[edx+0x2b];
  test ah,0x40`, `mov dl,[edx+0xb]; or dl,0x40; mov [eax+0xb],dl`; OW folds into `sub edx,[eax]`,
  `test byte ptr`, `or byte ptr`. Bitfields, locals and volatile do not help.
- `isel` misc: retail `lea edx,[eax*4]` vs OW `mov edx,eax; shl edx,2`; retail keeps `x == x`
  (`cmp eax,eax`), OW folds it; retail `cwde; test eax,eax` for a `short >= 0`, OW `test ax,ax`;
  the memcmp intrinsic's `xor eax,eax` is `31c0` in retail, `33c0` in OW.
- `cse1`: OW propagates a known compare value (`b == 1` then `mov eax,edx`), retail materialises
  `mov eax,1`.

## Loops: retail rotates them; write `if (guard) do { ... } while (cond);` (session 2).

Problem: any counted or list loop. Symptom: retail `test; jle out` guard, body, bottom
`cmp; jl top`; OW keeps a `for`/`while` as top test + `jmp` back. Fix: write the rotated form by
hand: `if (m > 0) do { ... } while (i < m);` (func_000372F0, func_00032650) or for a sentinel list
`if (m != &head) do { ... } while (m != &head);` (func_0001A990, func_0001A9C0). With `-ot` a plain
`for (n = s->f8, p = s->f14; n != 0; n--, p++)` also rotates (func_0001C330).

## Call sites: Watcom 10 assumes callees preserve argument registers -> `#pragma aux X modify exact [eax]`.

Problem: a value in an argument register is reused after a call. Symptom (func_0002B520):
retail `xor edx,edx; call func_000523F0; mov [D_000CFB28],edx`, OW re-materialises `xor eax,eax`
after the call. Fix: on that one callee, `#pragma aux func_000523F0 modify exact [eax]`. Never
`#pragma aux default ...`: that also changes the definitions (they start saving parameter
registers, which retail definitions do not). Related: if retail sets EDX before a call to a 1-arg
function, that is the next call's argument hoisted, so declare the first callee with one parameter.

## Hidden register parameters: unsaved EBX/ECX, or a scratch value in ESI/EDI (session 2).

Problem: the prologue does not push EBX (or ECX) but the body clobbers it, or retail picks ESI/EDI
for a one-shot scratch while EBX/ECX look free. Fix: those registers are (unused) parameters;
declare 3 or 4 params and pass them through (func_0001CBB0, func_000514C0, func_000514F0).

## Indirect call through a parameter or local: make the pointer `volatile` (session 2).

Symptom: retail `mov [ebp-8],ebx; call dword ptr [ebp-8]`, OW `call ebx`. Fix:
`int (*volatile c)()` (func_00036A20). Also: a parameter retail spills and re-reads
(`mov [ebp-x],edx; mov esi,[ebp-x]`) matches with `volatile int n` (func_000372F0).

## Variadic callees are watcall with stack args, not `__cdecl` (session 2).

`push str; call f; add esp,4` with no save of ECX/EDX around it = `void f(char *fmt, ...);`.
Declaring it `__cdecl` makes OW push/pop ECX/EDX in the caller (func_00012520, func_0003FBE0).

## Small source tricks that fixed register choice (session 2).

- Reuse a dead parameter: `a = (BeastObj *)a->field_3C; ((BeastState *)a)->field_20->field_4++;
  g(a);` keeps EAX like retail; a new local went to EDX (func_0003C1B0).
- Load into a local: `IniLine *p = G; if (p->next) G = p->next;` (func_000696B0).
- Two calls differing in one constant: write both calls in if/else, not a ternary argument; OW
  tail-merges the common suffix exactly like retail (func_00047E50).
- Inline port I/O: OW `conio.h` `inp` encodes `2b c0 ec`, retail `29 c0 ec`. Define your own:
  `#pragma aux snd_inp = 0x29 0xc0 0xec parm [edx] value [eax] modify exact [eax];` (func_0001CAD0).
- Hand-written asm callee with odd registers: `#pragma aux func_0004C0F7 parm [eax] [edx] [ecx]`.
- A function whose VA is not 16-byte aligned is not Watcom C (`-zm` aligns all); skip it.

## Drop `-ob`: Open Watcom's branch prediction moves `if` bodies behind the epilogue (kickoff).

Found 2026-09-24 (kickoff) on func_0001EB90 / func_0003B6A0 / func_0006BA10, all
`if (cond) store;` at the end of a function. Retail: `jne skip; mov [..],..; skip: epilogue`.
`-ox` (= `-obmiler -s`) gives `je body; epilogue; ret; body: mov [..],..; jmp epilogue`.
`-omiler` (everything in `-ox` except `b`) matches all three and keeps every earlier match; `-or`
is the one letter that is required (`-oe`/`-oi`/`-ol`/`-om` alone lose one probe). Flags are now
`-s -of+ -5r -omiler -zm -zp1`.

## Goto-shaped loops get close; Open Watcom still threads the first test (OPEN, patched-compiler class).

Found 2026-09-24 (kickoff). Writing func_000121B0 as `top: if (i != 0x54) f(i); i++; if (i < 0xC4)
goto top;` reproduces retail's block order except for one thing: OW emits `jmp` over the first
`cmp edx,0x54` because it knows `i == 0` there. func_00053700 (`if (!p) return; while (n > 0) {
n--; *p++ = 0; }`) differs the same way (guard duplicated instead of jumping to the bottom test).
Watcom 10.x did neither. No `-o` letter turns it off. This is a compiler-patch job (PLAN 1.7);
collect every such function in `tools/difficult_functions` with the tag `jt`.

## Pass-through wrappers match with an old-style callee declaration (kickoff, 38 functions).

Found 2026-09-24 (kickoff): `push ebp; mov ebp,esp; call X; mov esp,ebp; pop ebp; ret` is a
wrapper that hands its own EAX/EDX/EBX/ECX to X untouched. `void X(); void f(void) { X(); }`
reproduces it exactly (no argument setup is emitted). `return K;` (`mov eax,K` / `xor eax,eax`)
and `X(K)` wrappers likewise. `tools/auto_families.py` proposes these, verifies them in one
scratch compile and lands only exact matches; the build gate still has the last word. When the
callee's real prototype is known, give the wrapper matching parameters — the bytes do not change.

## Empty functions are 7 bytes: `push ebp; mov ebp,esp; mov esp,ebp; pop ebp; ret` (kickoff).

Found 2026-09-24 (kickoff): 43 functions are exactly `55 89e5 89ec 5d c3` (plus zero fill).
`void f(void) {}` matches every one under `-of+`; arguments do not change the bytes, so the
prototype is free to follow the call sites later. They cluster in `sound.c` (0x1BA90..0x1C9E0)
and `network.c`: debug / feature hooks compiled out in the retail build [H].

## LE data pages are relative to the stub MZ, not to the start of the file (kickoff).

Discovered 2026-09-24 (kickoff) in `tools/le.py`. Symptom: every one of the 20,192 fixups
pointed at bytes that did not contain its target offset, and the "relocated" disassembly of a
switch turned `and eax,0xff; jmp cs:[eax*4+tbl]` into `and eax,0x500000ff; push edx`.
KKND.EXE is `MZ (DOS/4GW Pro) … MZ stub @0x26654 … LE @0x28FEC`; the LE `data pages offset`
(header +0x80) is measured from the MZ whose `e_lfanew` points at the LE (0x26654 + 0x2998 ==
0x28FEC). Fix: find that stub (`LE._find_stub`) and add its offset. Check that proves it: the
raw 32-bit value under every OFF32 fixup equals the target's object-relative offset (0 bad of
20,188).

## OFF32 fields hold object-relative offsets; decode `.load(relocate=True)` before disassembling.

Discovered 2026-09-24 (kickoff). A switch `jmp dword ptr cs:[eax*4 + 0x26a0]` really reads the
table at 0x126A0 (object 1 base 0x10000 + 0x26A0). Function discovery must use the relocated
image or it follows nothing through tables and pointers (32 switch tables were invisible, 0 found
before the fix). The build compares *unrelocated* bytes, and masks relocated fields on both sides.

## `-zm` explains the 16-byte zero padding and forbids cross-function tail merging.

Discovered 2026-09-24 (kickoff) on func_00012390. With several functions in one file,
`wcc386 -ox` cross-jumps an identical epilogue into the *previous* function
(`jmp <prev>+n` replacing `lea esp,[ebp-4]; pop edx; pop ebp; ret`). The retail code never does,
and every function is followed by zero fill up to a 16-byte boundary. `-zm` (each function in its
own code segment, paragraph-aligned by the linker) gives both: separate segments cannot share
tails. The OMF reader therefore walks every CODE segment, not just `_TEXT`.

## Zero-extension of a `u8` argument: `-4r`/`-5r` emit `and eax,0xff`, `-3r` emits `movzx`.

Discovered 2026-09-24 (kickoff) on func_000100C0 (`void f(u8 c) { g(c); }` →
`and eax,0xff; call g`). Evidence for a 486/Pentium code target. `-4r` and `-5r` are not yet
distinguished — look for a Pentium-only scheduling choice to split them.

## `-of+` is the frame option: every function gets `push ebp; mov ebp,esp`.

Discovered 2026-09-24 (kickoff). Retail leaf functions with no locals still set up EBP and tear
down with `mov esp,ebp; pop ebp` (no saved regs) or `lea esp,[ebp-4*n]; pop …; pop ebp` (saved
regs). `-of` alone only frames functions that need it; `-of+` frames all of them.

## Loop with an `if` whose condition is known false on entry: Open Watcom jumps into the body, retail does not (OPEN).

Seen 2026-09-24 (kickoff) on func_000121B0:
`for (i = 0; i < 0xC4; i++) if (i != 0x54) f(i);`. Retail: `xor edx,edx; L: cmp edx,0x54;
je S; mov eax,edx; call f; S: inc edx; cmp edx,0xc4; jl L`. Open Watcom 1.9 and 2.0 (every
-o combination tried, 4 source shapes: for/while/do/continue) propagate `i==0` into the first
test and enter the loop at the call, or rotate the test. Hypothesis: Watcom 10.x lacked this
jump threading. Parked in `tools/difficult_functions`. Candidate levers: `volatile` index (costs
memory traffic, probably wrong), a real Watcom 10.x `wcc386`.
