/* uncover.c: 53 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "uncover.h"
/* decls */
extern char D_000C3032[];
extern char D_000C3050[];
void func_0001DFB0();
extern UncCtl *D_000D0E5C;
extern void *D_000D0E44;
extern void *D_000D0E54;
extern void *D_000D0E38;
extern void *D_000D0E1C;
extern char D_000C2F6C[];
void func_0001FF60();
void func_0001AA80();
#pragma aux func_0001AA80 modify exact [eax];
void func_0004C09C();
UncTgt *func_0002A070();
void func_0004B670();
void func_0001A060();
void func_0001CBF0();
void func_00051040();
extern UncPos *D_000D0E48;
extern s32 D_000D0DF8;
extern s32 D_000D1330;
void func_0004DEC7();
void func_0001CCC0();
void func_000510C0();
int func_0001CF40();
int func_00051130();
extern UncNode D_000D1320;

void func_0004F670(void)
{
    UncCtl *c = D_000D0E5C;
    UncPos *p;
    c->f8->f18 = 0;
    func_0001FF60(c);
    p = D_000D0E48;
    p->f68->f18 = 0;
    func_0001AA80(p);
    func_0004C09C(D_000D0E44, D_000C2F6C, 0x243);
    func_0004C09C(D_000D0E54, D_000C2F6C, 0x244);
    func_0004C09C(D_000D0E38, D_000C2F6C, 0x245);
    func_0004C09C(D_000D0E1C, D_000C2F6C, 0x246);
}
void func_0004F700(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000503A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050680);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050C30);
void func_00050D30(void *o)
{
    UncTgt *p = func_0002A070(o);
    if (p != 0 && D_000D0E48 != 0) {
        func_0004B670(0, 0x5e7, 0, p->f6c);
        func_0004B670(0, -2, 0, p->f6c);
        func_0001A060(o, 0x80000000, 1);
        func_0004B670(0, 0x5e8, 0, p->f6c);
        func_0004B670(0, -2, 0, p->f6c);
    }
}
void func_00050DB0(s32 a, s32 b)
{
    UncPos *p = D_000D0E48;
    s32 x = D_000D0DF8;
    p->f88 = 1;
    p->f14 = b << 8;
    p->f88 = 1;
    p->f10 = (a - (x + 4)) << 8;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050DF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050E20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050E50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00050FF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051040);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000510C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051130);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051250);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000512B0);
void func_00051480(UncUnit *u, s32 b)
{
    if (u->f18->f4c != 0x1000) func_0001CBF0(u, u->fac, u->fb0, u->fa8, b);
    else func_00051040(u, b);
}
void func_000514C0(UncUnit *u, s32 b, s32 c, s32 d)
{
    if (u->f18->f4c != 0x1000) func_0001CCC0(u, b, c, d);
    else func_000510C0(u, u->f5c->f10, u->f5c->f14);
}
int func_000514F0(UncUnit *u, s32 b, s32 c, s32 d)
{
    if (u->f18->f4c != 0x1000) return func_0001CF40(u, b >> 13, c >> 13, d);
    if (func_00051130(u, b, c, d) == 4) return 0;
    return 5;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051530);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000515E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000516D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051830);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051B00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051B50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051BC0);
int func_00051C20(s32 a, s32 b, s32 c, s32 d)
{
    if (a != c && b != d) {
        a -= c;
        if (a <= 0) a = -a;
        b -= d;
        if (b <= 0) b = -b;
        if (a != b) goto no;
    }
    return 1;
no:
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051C50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051CF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051E40);
void func_00051F10(void) { func_0004DEC7(D_000D1330); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051F30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00051FE0);
int func_00052070(s32 type)
{
    UncNode *n;
    if (type == 0x2e || type == 0x2f) return 1;
    for (n = D_000D1320.next; n != &D_000D1320; n = n->next) {
        if (type == n->f8) {
            if (n->f8 == 0x41 || n->f8 == 0x42) {
                func_0001DFB0(0, D_000C3032);
                return 0;
            }
            if (n->fc >= 4) {
                func_0001DFB0(0, D_000C3050);
                return 0;
            }
            return 1;
        }
    }
    return 1;
}
s32 func_000520E0(s32 key)
{
    UncNode *p;

    for (p = D_000D1320.next; p != &D_000D1320; p = p->next)
        if (key == p->f8) return p->fc;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052110);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052140);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000521B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052290);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052340);
void func_00052390(UncGrid *g)
{
    UncGridNode *n;
    s32 x = 0, y = 0;
    for (n = g->f8; n != 0; n = n->next) {
        if (y > 0 && y < g->f10 - 1 && x > 0 && x < g->fc - 1)
            n->f4->f18 = g->f14->f84->fc;
        x++;
        if (x >= g->fc) { y++; x = 0; }
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000523F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052470);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052790);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052880);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000528B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00052A60);
int func_00052AC0(s32 a, s32 b, s32 c, s32 d, UncEnt *e)
{
    e->f40(e);
    return 0;
}
