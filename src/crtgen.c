/* crtgen.c: 26 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "crtgen.h"
/* decls */
extern CgNode *D_000CF5D4;
extern CgNode *D_000CF620;
extern s32 D_000CF600;
extern s32 *D_000CF60C;
extern s32 D_000CF5F8;
extern char D_000BDF0C[];
void func_0004D47C();
void func_000290B0();
extern char D_000BDF18[];
void func_000287B0();
void func_000699E0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_000285D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00028630);
void func_00028770(s32 a) { func_000287B0(a, 0); }
void func_00028790(s32 a) { func_000287B0(a, 1); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_000287B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000288B0);
void func_00028EA0(CgNode *n)
{
    CgNode *h;
    n->f8->f78 = 0;
    if (n->prev != 0) n->prev->next = n->next;
    else D_000CF5D4 = n->next;
    if (n->next != 0) n->next->prev = n->prev;
    h = D_000CF620;
    D_000CF620 = n;
    n->next = h;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00028EF0);
void func_00028FF0(void)
{
    s32 p = D_000CF600;
    if (p != 0) {
        func_0004D47C(D_000CF60C, p, D_000CF5F8, D_000BDF0C, 0xa5, 4);
        func_000290B0();
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000290B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029180);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000291C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002924B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029260);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029288);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002929D);
void func_000292C0(s32 a, s32 b) { func_000699E0(a, b, D_000BDF18); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_000292D4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000292E8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000292FC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002931C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029358);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029400);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000295D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029600);
