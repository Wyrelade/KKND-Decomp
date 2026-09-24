/* savegame.c: 4 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
#include "savegame.h"
/* Watcom 10 library helpers: stack arguments, callee pops, clobber EBX/ECX/EDX. */
void func_00014D18(int line, char *file);
#pragma aux func_00014D18 parm routine [] modify [eax ebx ecx edx];
void func_00014D9B(char *, char *, ...);
#pragma aux func_00014D9B modify [eax ebx ecx edx];
extern char D_000C521C[];
extern char D_000B7B38[];
extern char D_000D7050[];
extern SaveSlot D_000D6E84[];
extern s32 D_000BB284;
int func_00026700(char *name, s32 v);
int func_00026760(char *name, s32 v);

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C460);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C530);
int func_0006C660(int n)
{
    func_00014D18(0x2d, D_000C521C);
    func_00014D9B(D_000D7050, D_000B7B38, n);
    return func_00026700(D_000D7050, D_000D6E84[n].field_0);
}
int func_0006C6B0(int n)
{
    func_00014D18(0x17, D_000C521C);
    func_00014D9B(D_000D7050, D_000B7B38, n);
    if (func_00026760(D_000D7050, D_000D6E84[n].field_0) == 0)
        return 0;
    D_000BB284 = 4;
    return 1;
}
