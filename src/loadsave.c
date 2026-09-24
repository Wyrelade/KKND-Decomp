/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* loadsave.c: 46 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "loadsave.h"
/* decls */
extern s32 D_000CECD0;
extern s32 D_000BDD84;
extern s32 D_000BDD80;
extern s32 D_000BDD90;
void func_00069ED0();
extern u32 D_000C4D00;
extern s32 D_000C4784[];
extern LsNode D_000CDE94;

INCLUDE_ASM("asm/DOS/nonmatchings", func_00020B60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000210D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000217F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00021B80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00021E10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00021E80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00021F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00023610);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00024130);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00024270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00024310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00024640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000247E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00025560);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026100);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026190);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026260);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026300);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026330);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026370);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000264E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026580);
LsNode *func_000265F0(s32 key)
{
    LsNode *p;

    if (key != -1)
        for (p = D_000CDE94.next; p != &D_000CDE94; p = p->next)
            if (key == p->f134) return p;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026620);
s32 func_00026670(u32 i)
{
    if (i < 1 || i > D_000C4D00) return 0;
    return D_000C4784[i];
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000266A0);
s32 func_000266F0(void) { return D_000CECD0; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026760);
s32 func_000267C0(void) { return D_000BDD84; }
s32 func_000267D0(void) { return D_000BDD80; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_000267E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026A90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026BB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026CA0);
void func_00026D00(void)
{
    if (D_000BDD90 == 0) func_00069ED0();
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026D20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026DB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026EF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026F40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026F70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026F90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00026FE4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027124);
