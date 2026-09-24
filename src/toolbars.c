/* toolbars.c: 60 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "toolbars.h"
/* decls */
void func_0002B9F0();
extern int D_000BE3C4;
TbMob *func_00055C80(TbBld *);
void func_0001C600(TbMob *, int, int, int);
void func_0001A6E0(TbMob *, s32);
void func_00051930(TbMob *, s32);
void func_0002D120();
void func_0002CB20();
extern TbEntry *D_000CFD6C;
void func_0001A150(int);
extern void *D_000BDE74;
extern int D_000CFB28;
void func_000523F0(int, int);
#pragma aux func_000523F0 modify exact [eax]
void func_0002A020(int);
extern TbGlobal *D_000B98D8;
extern int D_000CFE80;
extern int D_000CC680;
extern int D_000CFD68;
extern int D_000CFDC0;
void func_0002CB50(int, int);
int func_0001A060(int, int, int);
TbWidget *func_0002C300(int, int, void (*)(), int, int, int, int, int);
void func_0002B6C0();
void func_0002BEC0();
void func_00019F90(int);
void func_0004B670(int, int, int, int);
int func_00027DF0(u8 *);
void func_0002D1A0(TbObj *);
void func_0001AA80(int);
void func_0001E270(TbObj *);
void func_0004DEC7(int);
void func_00050DF0();
void func_00050E20();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A4F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A540);
void func_0002A8B0(void)
{
    func_0004B670(0, 0x5FA, 0, D_000CFE80);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A8E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AA10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AAA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AB60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AC90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AE30);
void func_0002AE90(void)
{
    func_00050DF0();
}

void func_0002AEA0(void)
{
    func_00050E20();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AEB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AEE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AF60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002AF90);
void func_0002B010(void)
{
    func_0004B670(0, 0x5F0, 0, D_000CC680);
}

void func_0002B040(void)
{
    func_0004B670(0, 0x5EF, 0, D_000CC680);
    func_0002A020(1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B070);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B0A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B120);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B1C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B2B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B3A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B400);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B440);
void func_0002B4C0(void)
{
    func_0004B670(0, 0x5EC, 0, D_000CC680);
}

void func_0002B4F0(void)
{
    func_0002A020(0);
    func_0004B670(0, 0x5EB, 0, D_000CC680);
}

void func_0002B520(TbObj *p)
{
    func_000523F0(p->field_20, 0);
    D_000CFB28 = 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B5D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B690);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B6C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002B9F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002BEC0);
void func_0002C1D0(int a)
{
    for (;;) {
        if (func_0001A060(a, 1, 0) & 1)
            func_00019F90(a);
    }
}

void func_0002C200(void)
{
    func_0004DEC7(D_000CFD68);
    func_0004DEC7(D_000CFDC0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C220);
void func_0002C280(TbList *l, TbEntry *e)
{
    TbEntry *t;
    if (l) {
        s32 *a;
        s32 *b;
        l->field_C--;
        e->prev->next = e->next;
        e->next->prev = e->prev;
        if (e->field_18) {
            a = &e->field_1C->field_8;
            b = &e->field_1C->field_C;
            if (*a) {
                func_0001AA80(*a);
                *a = 0;
            }
            if (*b) {
                func_0001AA80(*b);
                *b = 0;
            }
        }
    }
    func_0001AA80(e->field_24);
    func_0001A150(e->field_8);
    t = D_000CFD6C;
    D_000CFD6C = e;
    e->next = t;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C300);
TbWidget *func_0002C450(int a, int b, int c, int d, int e, int f, int g)
{
    TbWidget *r = func_0002C300(a, b, func_0002B9F0, c, 0, f, g, 0xBABA);
    if (r) {
        r->field_1C = d;
        r->field_18 = e;
    }
    return r;
}
void func_0002C490(int a, int b, int c, int d, int e)
{
    func_0002C300(a, b, func_0002B6C0, c, d, 0, e, 0xBBBB);
}

void func_0002C4C0(int a, int b, int c, int d, int e)
{
    func_0002C300(a, b, func_0002BEC0, c, d, 0, e, 0xBABA);
}

void func_0002C4F0(int a, int b, int c, int d, int e)
{
    func_0002C300(a, b, func_0002BEC0, c, 0, d, e, 0xBABA);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C520);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C670);
void func_0002C740(TbSrc *a, TbDst *b)
{
    b->field_2C = a->field_18 + 0x20000000;
    if (a->field_54) {
        b->field_24 = (a->field_10 >> 8) - a->field_54->field_0;
        b->field_28 = (a->field_14 >> 8) - a->field_54->field_4;
        b->field_18 = a->field_54->field_C;
    } else {
        b->field_18 = 0;
    }
    b->field_20 = D_000BDE74;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C7A0);
void func_0002C960(TbObj *p)
{
    func_0001A060(p->field_C, 0x80000000, 0x28);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C980);
void func_0002CAB0(TbObj *p)
{
    p->field_B4 = (func_00027DF0(D_000B98D8->field_8->field_14) << 8) + 0x2000;
}

void func_0002CAE0(int a)
{
    func_0002CB50(a, 0);
}

void func_0002CB00(int a)
{
    func_0002CB50(a, 1);
}

void func_0002CB20(TbObj *p)
{
    func_0002D1A0(p);
    func_0001AA80(p->field_5C);
    func_00019F90(p->field_C);
    func_0001E270(p);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CB50);
void func_0002CC20(TbBld *t)
{
    TbMob *s = t->field_5C;
    TbMob *n;
    if (s->field_18 > 0) {
        n = func_00055C80(t);
        if (n) {
            n->field_18 = t->field_5C->field_18 + 0x100;
            n->field_68->field_10 = func_0002D120;
        }
        func_0001A060(t->field_C, 0x80000000, 0x14);
    } else {
        /* the store sits after the argument set-up in retail: comma expression in the first argument */
        func_0001C600((s->field_18 = 0xFF, s), 9, D_000BE3C4, 0);
        s->field_C = 0x16;
        func_0001A6E0(s, 0);
        s->field_60 = 0x20000000;
        s->field_18 = 0x300;
        func_00051930(s, 0x40);
        t->field_40 = func_0002CB20;
        func_0001A060(t->field_C, 0x80000000, 0x14);
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CCD0);
