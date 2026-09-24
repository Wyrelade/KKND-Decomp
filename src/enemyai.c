/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* enemyai.c: 21 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "enemyai.h"
/* decls */
void func_00059B10();
void func_0001A060();
void func_0004B670();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00058960);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00058B30);
void func_00059AE0(AiEnt *e)
{
    e->f40 = func_00059B10;
    func_0001A060(e, 0x80000000, 0x3c);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00059B10);
void func_0005A180(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005A190);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005A450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005A4E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005A760);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005ABE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005AEB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005AFE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005B070);
void func_0005B1C0(AiPlayer *pl, AiGroup *g, s32 x, s32 y)
{
    AiMsg m;
    AiNode *n;

    m.f0 = pl->f2a0;
    g->f3c = x;
    m.f4 = x;
    g->f40 = y;
    m.f8 = y;
    g->f24 = 0;
    for (n = g->fc.next; n != &g->fc; n = n->next)
        func_0004B670(0, 0x5f4, &m, n->fc->fc);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005B210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005B510);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005B850);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005B8E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005BCB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005C8B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005C960);
