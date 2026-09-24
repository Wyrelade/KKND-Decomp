# Agent C notes (netipx, network, serial, netzutil, netz, nipx, message, uinput, controlc, toolbars)

## Candidate filter

- Any function whose VA is not 16-byte aligned is not Watcom C output (`-zm` aligns every
  function); they also tend to use `8bec`/`leave` or jump into other functions. Skip them.

## Codegen findings (problem -> symptom -> fix)

### `-ot` belongs in the flags (PROJECT-LEVEL: please consider `-omilert` in cflags.txt)
- Symptom: argument set-up order. Retail `mov edx,0x60c; mov ecx,[D_000CFB3C]; xor ebx,ebx;
  xor eax,eax; mov ecx,[ecx+8]; call` (loads the complex argument straight into its register,
  splitting the load chain); OW default builds it in EAX first (`mov eax,[D]; ... mov ecx,[eax+8];
  xor eax,eax`). func_0002A350, func_0002A380, func_0006C280.
- Fix: add `t` to the optimisation letters: `-s -of+ -5r -omilert -zm -zp1`. I checked every
  src/*.c file: with `-omilert` no currently matched function is lost (sound.c 30->34 and
  uncover.c 5->7 even gain). My 10 modules carry a first-line override
  `/* cflags: -s -of+ -5r -omilert -zm -zp1 */` (match.py ignores that line: pass `--flags`).

### Call sites: Watcom 10 assumes the callee preserves its argument registers
- Symptom: retail reuses an argument register after a call (func_0002B520:
  `mov eax,[eax+0x20]; xor edx,edx; call func_000523F0; mov [D_000CFB28],edx`). Open Watcom
  re-materialises the value after the call (`xor eax,eax; mov [..],eax`), because by default it
  treats the callee's parameter registers as clobbered.
- Fix: `#pragma aux <callee> modify exact [eax]` on that callee (only the callee!).
  ```c
  void func_000523F0(int, int);
  #pragma aux func_000523F0 modify exact [eax]
  void func_0002B520(TbObj *p) { func_000523F0(p->field_20, 0); D_000CFB28 = 0; }
  ```
- Do NOT use `#pragma aux default modify exact [eax]`: it also changes the *definitions*
  (every function then saves the parameter registers it modifies, e.g. `push edx` in front of
  an `and edx,0xff`). Retail definitions do not save modified parameter registers
  (func_0005F7F0, func_0002C490 modify EDX/EBX/ECX without saving). So in retail: callee side
  clobbers parameter registers, caller side assumes they survive. (Watcom 10.x inconsistency.)
- Also: a value set in a non-parameter register before a call survives it (normal); if retail
  sets EDX before a call to a 1-arg function, that is the next call's argument hoisted: declare
  the callee with ONE parameter (func_0002B4F0: `func_0002A020(0); func_0004B670(0,0x5EB,0,D)`
  gives `xor eax,eax; mov edx,0x5eb; call A020; ... call 4B670`).

### Hand-written asm callees with non-standard parameter registers
- func_0004C0F7 (message.c, unaligned = asm) takes (EAX, EDX, ECX): caller func_00029FF0 sets
  ecx=8, eax=ptr, edx=0 and leaves EBX alone. `#pragma aux func_0004C0F7 parm [eax] [edx] [ecx]`
  reproduces the argument setup.

### Known unmatchable-with-OW classes found here (skip quickly)
- `mul`: multiplication by a constant (struct array index with odd size, e.g. 0x1B, 0x38):
  retail `mov edx,eax; shl eax,3; sub eax,edx; ...`, OW always `imul eax,eax,K` (every -3r..-6r,
  -os/-ot tried). func_000142D0, func_0004C7B0.
- `ci`: constants stored to globals. Retail loads constants into registers first when several
  stores happen (`mov ebx,1; xor edx,edx; mov [A],ebx; mov [B],edx`), OW uses
  `mov dword ptr [A],1`. func_0004CDC0, func_0004CD20, func_0004CD70.
- `ra`: register allocation preference. For a value that must survive a call or is loaded
  from memory and then passed in EAX, retail prefers EBX (then EDX...) where OW prefers
  ECX/EDX/EAX: func_000139F0 (`ebx` vs our `ecx`), func_0001FEF0, func_0005F4B0,
  func_0002B690, func_0002AEB0, func_00013910 (retail `xor edx,edx` where OW uses `xor eax,eax`).
- `isel`: `lea edx,[eax*4]` (retail) vs `mov edx,eax; shl edx,2` (OW) for a scaled index
  into a pointer loaded later (func_000141C0).
- `cse1`: OW propagates a known comparison value (`b == 1` -> `mov eax,edx`), retail
  materialises the constant (`mov eax,1`) (func_0002B690).
- memcmp intrinsic: identical except `xor eax,eax` is encoded `31c0` in retail and `33c0` by OW
  (func_0004C220). Would need a custom `#pragma aux` inline sequence.

## Name evidence (VA -> name)

## Hard / skipped functions (function, attempts, best bytes differing, reason)

| function | attempts | best diff | reason |
|---|---|---|---|
| func_0004C220 | 1 | 1 | memcmp intrinsic xor encoding |
| func_0004C7B0 | 3 | 18 | mul |
| func_0004CDC0 / CD20 / CD70 | 4 | 14 | ci |
| func_00013910 | 2 | 9 | ra (edx vs eax) |
| func_000139F0 | 3 | 4 | ra (ebx vs ecx) |
| func_00013A60 | 1 | 19 | jt (loop guard) |
| func_00013930 | 1 | 15 | ci/ra |
| func_000141C0 | 3 | 22 | isel |
| func_000142D0 | 2 | 31 | mul |
| func_00013AE0 | 1 | 46 | not investigated further (loop) |
| func_0001FEF0 | 3 | 5 | ra |
| func_0005F4B0 | 2 | 27 | ra |
| func_0005F880 / func_0005E6D0 | 1 | 10 | ci/ra |
| func_00029FF0 | 2 | 9 | ci/ra (retail zeroes edx for the store) |
| func_0002B690 | 1 | 21 | ra + cse1 |
| func_0002AEB0 / AF60 / B070 | 1 | 14 | ra/ci |
