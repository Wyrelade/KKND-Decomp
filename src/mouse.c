/* mouse.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
extern s32 D_000CC924;
extern s32 D_000CC920;
extern s32 D_000CC8D8;
extern char D_000BD808[];
extern s32 D_000CC8A0;
int func_0004D47C(int a, void *b, int c, char *file, int line, int f);

int func_0001B250(int a)
{
    if (D_000CC8D8 == 0)
        return 0;
    func_0004D47C(a, &D_000CC8A0, 0x20, D_000BD808, 0x16b, 4);
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B290);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B300);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B370);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B3E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B460);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B4D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B710);
s32 func_0001B730(void)
{
    return D_000CC924;
}

s32 func_0001B740(void)
{
    return D_000CC920;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B780);
