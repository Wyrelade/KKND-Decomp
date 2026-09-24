/* misc.c: 20 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
#include "misc.h"
void func_0004B670();
void func_00028790(int);
int func_0004BFD7(int);
void func_00027D7B(int);
extern u8 D_000B96B8[];
extern s32 D_000BB8B0;
extern char D_000B1850[];
s32 InitAddrList(int a);
void func_0004C080(char *fmt, ...);

INCLUDE_ASM("asm/DOS/nonmatchings", func_000112B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011A50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011D90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011EF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012020);
void func_00012080(void)
{
    func_00027D7B(1);
}

int func_000120A0(char *s)
{
    do {
        if (!(D_000B96B8[(u8)(*s++ + 1)] & 0x20))
            return 0;
    } while (*s != 0);
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000120D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012140);
void func_000121B0(void)
{
    int i;
    for (i = 0; i < 0xC4; i++)
        if (i != 0x54) func_00028790(i);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000121E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012240);
int func_000122A0(MiscObj *a, MiscObj *b, int c, int d, int e)
{
    if (a->field_6C)
        func_0004B670(0, -2, b->field_6C, a->field_6C);
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000122D0);
/* Busy-wait until func_0004BFD7(0) changes (tick / vsync counter). */
void func_00012390(void)
{
    int t = func_0004BFD7(0);
    while (t == func_0004BFD7(0))
        ;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000123B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012420);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012470);
int func_00012520(void)
{
    D_000BB8B0 = InitAddrList(10);
    if (D_000BB8B0 == 0)
        func_0004C080(D_000B1850);
    return 0;
}

