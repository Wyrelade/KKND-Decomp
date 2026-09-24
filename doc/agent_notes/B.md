# Agent B notes (vid_dump key2 ini mouseptr gfx fmv mob misc main mouse vesa effect tasks files key savegame)

## Codegen findings (problem -> symptom -> fix)

- **Variadic callees are watcall-with-stack, not cdecl.** `push str; call printf-like; add esp,4`
  with NO save of ecx/edx around it = `void f(char *fmt, ...);` (plain, no `__cdecl`). Declaring
  it `__cdecl` makes OW push/pop ecx/edx in the caller. (misc.c func_00012520)
- **Sentinel-list loops: write the guard + do-while explicitly.** Retail
  `cmp eax,&head; je none; L: ...; mov eax,[eax]; cmp eax,&head; jne L` (bottom test duplicated).
  `for`/`while` in OW gives `jmp` back to the top test. `if (m != &head) do {...} while (m != &head);`
  matches (mob.c func_0001A990 / func_0001A9C0).
- **Load-into-local keeps the pointer in its own register.** `IniLine *p = G; if (p->next) G = p->next;`
  matched where `if (G->next) G = G->next;` put everything in EAX (ini.c func_000696B0).

## Recurring non-matching classes (Watcom 10.x vs OW register allocation) [tag ra]

- Retail loads memory operands into a scratch register before ALU ops
  (`mov ebx,[eax]; sub edx,ebx`, `mov ah,[edx+2b]; test ah,40`), OW folds them
  (`sub edx,[eax]`, `test byte [edx+2b],40`). No source trick found yet (locals, volatile, flags).
- Retail picks EBX before ECX for a fresh temp; OW picks ECX (3-byte diffs in list unlink/insert,
  mob.c func_0001A9F0 / func_0001AA20, fmv.c func_00020600).
- Retail stores constants via a register (`mov edx,1; mov [G],edx`, `xor edx,edx; mov [G],edx` then
  reuses EDX=0 as a call argument, even after the call since callee preserves EDX); OW uses
  `mov [G],imm` / re-materialises. (mouse.c func_0001B750, effect.c func_00028280/282B0, ini.c func_0006B2C0)
- Pure `call X` wrapper where retail saves EBX/ECX/EDX: callee has a non-watcall convention; neither
  `__cdecl` nor `__syscall` reproduces push ebx/ecx/edx (vesa.c func_000687F0).
- `short` return compared `>= 0`: retail `cwde; test eax,eax`, OW `test ax,ax` (fmv.c func_000205D0, 1 byte).

## Hard / skipped functions

| function | attempts | best diff | reason |
|---|---|---|---|
