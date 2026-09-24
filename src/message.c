/* message.c: 49 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "message.h"
extern MsgNode *D_000D01B0;
extern int D_000D01B4;
extern char D_000C20EC[];
void func_0004C09C(int, char *, int);

void func_0004B570(void)
{
    func_0004C09C(D_000D01B4, D_000C20EC, 0xA4);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B590);
void func_0004B5C0(MsgNode *n)
{
    MsgNode *t = D_000D01B0;
    D_000D01B0 = n;
    n->next = t;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B5E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B600);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B670);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B720);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B781);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B7E1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B7E7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B7F9);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B807);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B80F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B818);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B824);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B849);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B858);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B87C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B8A7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B8FC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B96A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B991);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B9B4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B9D8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B9F3);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BA11);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BA53);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BA71);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BB32);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BC71);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BC95);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BE5A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BEBF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BFD2);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004BFD7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C004);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C02A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C02F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C035);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C059);
void func_0004C070(void)
{
}

void func_0004C080(void)
{
}

int func_0004C090(void)
{
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C09C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C0C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C0F7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C163);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C191);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C1AD);
