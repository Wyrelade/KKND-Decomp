/* mission.c: 24 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "mission.h"
/* decls */
extern s32 D_000BF620;
extern s32 D_000BDA4C;
extern s32 D_000BDA50;
extern s32 D_000CDE64[];
extern s32 D_000CDE48[];
void func_0004F710();
int func_0004F640();
extern MsNode D_000CDE94;
typedef struct { u8 _pad[0x10]; s32 field_10; s32 field_14; u8 _pad2[0x70]; s32 field_88; } MsnObj;
typedef struct { u8 _pad[0x38]; MsnObj *field_38; } MsnState;
extern s32 D_000BE7C8;
extern MsnState *D_000BE7E8;
extern s32 D_000BE8F8;
void func_0001B3E0(int, int);
void func_0002FB80(void *);
void func_0004B600(void *, int, int, int);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00030E00);
MsNode *func_00031230(s32 x, s32 y)
{
    MsNode *n;
    for (n = D_000CDE94.next; n != &D_000CDE94; n = n->next)
        if (n->f90 == 0 && y == n->f14 && x == n->f10) return n;
    return 0;
}
int func_00031270(s32 x, s32 y)
{
    MsNode *n;
    int r = 0;
    for (n = D_000CDE94.next; n != &D_000CDE94; n = n->next) {
        if (n->f90 == 0 && y == n->f14 && x == n->f10) {
            if (func_0004F640(n) == 0) return 2;
            r = 1;
        }
    }
    return r;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000312D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031500);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031560);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000315F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031660);
void func_00031740(MsBld *u, s32 p)
{
    MsCol *c;
    s32 k;
    if (p == D_000BF620) D_000BDA4C++;
    else D_000BDA50++;
    u->f14 = p;
    c = u->f5c->f68;
    k = D_000CDE64[p];
    c->f30 = D_000CDE48[k];
    if (u->f1c != 0) u->f1c->f4->f68->f30 = D_000CDE48[D_000CDE64[p]];
    func_0004F710(u);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000317B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031870);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031A00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031A20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031C00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031D30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031E30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031F10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032040);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000321D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032200);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032230);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000322E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032340);
void func_000323B0(void *a)
{
    MsnObj *m;
    switch (D_000BE7C8) {
    case 0: case 2: case 7: case 11:
        m = D_000BE7E8->field_38;
        m->field_88 = 1;
        m->field_10 = 0x14000;
        m->field_14 = 0xF000;
        m->field_88 = 1;
        func_0001B3E0(0x140, 0xF0);
        if (D_000BE8F8 != 0) func_0002FB80(a);
        func_0004B600(a, 0x5F6, 0, 0x11);
        break;
    }
}
