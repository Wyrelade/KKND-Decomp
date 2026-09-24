# Decompilation Learnings

Notes on the Watcom C 32-bit toolchain (`wcc386 -s -of+ -5r -omiler -zm -zp1`, register calling
convention) used by this project. Each entry was verified against real target machine code.
Append new entries at the top. Search with `python tools/learn.py <terms>`.

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
