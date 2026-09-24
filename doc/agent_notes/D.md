# Agent D notes (sound, bread, uncover, healthbr, loadsave, playctrl, units, crtgen, mission,
# enemyai, projectl, clanhall, schrap, machshop, building, tanker)

## Codegen findings

### `-ot` (favor time) matches retail better: add it to the flags (`-s -of+ -5r -omilert -zm -zp1`)
Problem -> symptom -> fix. (1) `x % n` after a computed value: retail `mov eax,edx; sar edx,0x1f;
idiv`, OW default `cdq; idiv` -> `-ot` emits the sar form (func_0001CB30). (2) Spilled arg: retail
`sub esp,4; mov [ebp-4],edx`, OW default `push edx` -> `-ot` gives the retail form
(func_0001CB00, 4x outp). (3) `for (n = s->f8, p = s->f14; n != 0; n--, p++) p->f0 = 0;` matches
only with `-ot` (func_0001C330: guard + bottom test, count in EAX). Checked every landed function
in src/*.c with `-omilert`: 149 OK / 0 FAIL (same as without). My modules carry the per-file
override `/* cflags: -s -of+ -5r -omilert -zm -zp1 */`; recommend making it global.
Note `tools/match.py` ignores the per-file override: pass `--flags` explicitly.

### Constant multiply: Watcom 10 strength-reduces, Open Watcom emits `imul` (tag `mul`, no flag fixes it)
Problem: indexing an array of non-power-of-2 structs (`tbl[i].f0` with sizeof 100, `&s->arr[n]` with
sizeof 0x38). Symptom: retail `mov edx,eax; shl eax,2; sub eax,edx; shl eax,3; add eax,edx;
cmp [eax*4+tbl],1` (i*25*4) or `lea edx,[ecx*8]; sub edx,ecx; shl edx,3` (n*56); OW 1.9 always
emits `imul eax,eax,0x64` / `imul eax,[eax+4],0x38`. Tried -3r/-4r/-5r/-6r, -os/-ot/-oa/-oc/-on/
-ou/-oh/-ok/-ol+: always imul. Writing the shifts by hand (`t=(i<<2)-i; t=(t<<3)+i; tbl[t]`)
gets the instruction sequence but with swapped registers, and is not source-faithful.
Examples: func_0001E0E0, func_0001C260, func_0001C1B0. Candidate for the patched compiler
(disable imul for constant multipliers / use the 10.x shift-add decomposition).

### Inline port I/O: define own `#pragma aux` with byte codes (conio.h `inp` encodes differently)
Problem: OW conio.h `inp` expands to `2b c0 ec` (sub eax,eax with the 2B opcode); retail has
`29 c0 ec`. Fix: `unsigned snd_inp(unsigned port);
#pragma aux snd_inp = 0x29 0xc0 0xec parm [edx] value [eax] modify exact [eax];` and
`#pragma aux snd_outp = 0xee parm [edx] [eax] value [eax] modify exact [];` (func_0001CAD0 OK).
`modify exact` is needed or the compiler reloads EDX for every call.

### Spilled argument: retail `sub esp,4; mov [ebp-4],edx`, OW `push edx` (func_0001CB00, OPEN)
Four `outp` calls with the 2nd arg needed after EDX is clobbered by the port: OW spills with
`push edx`; retail reserves the slot then stores. No fix found (2 attempts).

### `ebx` not saved => the function has (at least) 3 register parameters
If the prologue does not push EBX but the body clobbers it, EBX is an argument register:
declare a 3rd (unused) parameter. func_0001CBB0 got the right frame that way.

### `x = 0` store to a global: retail uses a free non-EAX register (func_0001C520, OPEN)
`void f(void) { D = 0; }` -> retail `push edx; xor edx,edx; mov [D],edx; pop edx`, OW
`xor eax,eax; mov [D],eax`. Tried `int` return without value, an unused EAX param: no change.

### Retail picks ESI/EDI for a scratch value while ECX/EBX are free => more register params
func_000514C0 / func_000514F0: retail used `mov esi,[eax+0x18]` for a one-shot compare and did
not save ECX. Declaring 4 parameters (a, b, c, d) and passing them through (`func_0001CCC0(u, b,
c, d)`) makes OW pick ESI too -> OK. Rule: unsaved-but-clobbered EBX/ECX = args; a scratch
value in ESI/EDI when EBX/ECX look free = those registers are (unused) args.

### Retail prefers EBX over ECX for the first scratch register (tag `rb`, OPEN)
func_00026620, func_00051480, func_0001C4E0, func_0001CB30: identical code except retail uses
EBX where OW uses ECX (push/pop too). Prototypes on the callee don't change it.

### `x == x` is kept by Watcom 10, folded by OW (func_00051BC0, a source bug `dy == dy`)
Retail `cmp eax,eax; jne`. OW folds the compare away. Unmatchable without tricks.

### 16-bit constant store: retail `mov edx,0x101; mov [ebp-0x24],dx`, OW `mov word [..],0x101`
func_000295D0 (union REGS for int386). No source fix found (1 attempt).

## Hard / skipped functions
| function | attempts | best diff | reason |
|---|---|---|---|
| func_0001C520 | 3 | 9 | global=0 through EDX instead of EAX |
| func_0001E0E0 | 3 | 27 | mul |
| func_0001C260 | 1 | 65 | mul |
| func_0001C1B0 | 1 | 58 | mul (+ materialized setb compare) |
| func_0001CBB0 | 5 | 7 | loop counter / pointer register swap (ECX/EBX) |
| func_0001CB30 | 2 | 4 | rb (EBX vs ECX) |
| func_0001C4E0 | 3 | 7 | rb; note `(D_000CC99E >> 16) != -1` gives the retail `mov ebx,[D]; sar ebx,16` |
| func_0001DF30 | 2 | 37 | retail loads both operands of `x - p->f` into registers (no memory operand fold) |
| func_0001DEE0 | 2 | 34 | same as DF30 |
| func_0001C7A0 | 1 | 19 | zero store via EDX (see C520) |
| func_0001E000 | 3 | 14 | retail keeps list head in EDX then `mov eax,edx` |
| func_0001BB00 | 1 | 48 | jt (for loop peeled/rotated) |
| func_0001BBF0 | 1 | 51 | jt |
| func_0001C3E0, func_0001DC00, func_0001DBA0, func_0001C200, func_0001C2B0, func_0001C090, func_0001B850, func_0001E1F0 | 0 | - | mul |
| func_0001CA00 | 0 | - | inline asm port loop, skipped |
| func_0001DA20 | 0 | - | not code (zero bytes) |
| func_00053820 | 1 | 30 | bread: retail `mov ah,[ebx+0x2b]; test ah,0x40`, OW `test byte ptr` |
| func_00053C90 | 1 | 99 | bread: register allocation (loads before compare) |
| func_00052CB4, func_00052C8C, func_00054679, func_0005467E | 0 | - | bread: hand-written asm (coroutine switch / no frame) |
| func_00052880 | 1 | 38 | mul (*10 as lea/add) |
| func_0005D290, func_0005D2B0 | 2 | 27 | retail `mov dl,[edx+0xb]; or dl,0x40; mov [eax+0xb],dl`, OW `or byte ptr` (bitfield tried) |
| func_0005E150 | 1 | 31 | loop register allocation |
| func_0005E091, func_0005E0AD | 0 | - | not Watcom (leave / stack args) |
| func_00026620 | 1 | 7 | rb |
| func_00030790 | 5 | 9 | zero store via EDX (volatile/unsigned/pointer/local/return variants tried) |
| func_000306A0 | 1 | 20 | jt (clamp: second test threaded) |
| func_000295D0 | 1 | 31 | 16-bit constant store via register |
| func_00051480 | 1 | 2 | rb |
| func_00051B00 | 1 | 65 | no memory-operand fold in first `sub` |
| func_00052110 | 1 | 19 | double `setne` (`(x != y) != 0`?) |
| func_00050DF0 | 1 | 22 | zero via EBX (EAX free) |
| func_00051BC0 | 1 | 89 | `x == x` folded |
