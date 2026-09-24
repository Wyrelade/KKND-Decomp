# Watcom 32-bit codegen model (short)

The general model that the `DECOMPILATION_LEARNINGS.md` entries instantiate. Read this first,
then search the journal (`python tools/learn.py <terms>`). Everything here is [C] for this exe
unless marked.

## Calling convention (`-5r`, Watcom register)

- Arguments: 1st **EAX**, 2nd **EDX**, 3rd **EBX**, 4th **ECX**, rest on the stack (pushed right
  to left, callee pops: `ret 4*n`, e.g. func_000122A0 `ret 4` has 5 args).
- Return value in **EAX** (EDX:EAX for 64-bit, ST(0) for floats [H]).
- Callee preserves every register it modifies except EAX (and the argument registers it
  receives): `push edx … pop edx` around a function that only uses EDX as a loop counter.
- Names: functions `name_` (trailing underscore), data `_name` (leading underscore).
  `#pragma aux` can change both — watch for library functions that do.

## Frames (`-of+`)

```
push ebp            ; always
mov  ebp, esp
push <saved regs>   ; in the order ebx, ecx, edx, esi, edi as used [H: order]
sub  esp, N         ; locals
...
lea  esp, [ebp - 4*saved]   ; or mov esp, ebp when nothing was saved
pop  <saved regs reversed>
pop  ebp
ret  [4*stack_args]
```

## Layout (`-zm`)

Each function is its own segment → linker aligns to 16 with zero fill; no tail sharing across
functions. Source order within a module ≈ address order [H: verify per module].

## Idioms seen

| C | Code |
|---|---|
| `u8` arg passed on | `and eax, 0xff` (not `movzx`) |
| `x = 0` | `xor reg, reg` |
| constant call arg | `mov eax, imm32` right before `call` |
| `while (a == f())` | re-evaluated `xor eax,eax; call f; cmp saved,eax; je` loop |
| `switch` (dense) | `cmp; ja default; jmp cs:[reg*4 + table]` with the table in the code object |
| far callback | `inc ebp; push ebp; mov ebp,esp … pop ebp; dec ebp; retf` |
