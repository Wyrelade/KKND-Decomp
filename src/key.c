/* key.c: 6 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
extern char D_000BD6E4[];
extern s32 D_000CC850;
int func_0004D47C(int a, void *b, int c, char *file, int line, int f);

int func_0001AE50(int a)
{
    func_0004D47C(a, &D_000CC850, 0x20, D_000BD6E4, 0x99, 4);
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AE80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AEB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AF90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B000);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B070);
