/* controlc.c: 45 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "controlc.h"
/* decls */
int func_0006C2B0(CcTgt *, s32, s32);
int func_0001DBA0(s32, s32);
int func_0001DC00(s32, s32);
void func_0006C0F0(CcTur *);
void func_0001DE10(s32 *, s32, s32);
void func_0001A5B0(s32, s32, s32);
CcHook *func_0001A010(CcOwner *, int);
void func_0006B9C0(CcHook *);
extern int D_000CD960[];
void func_0001A6A0(int, int, int);
void func_0006C170();
extern char D_000BB7F8[];
extern char D_000C3364[];
void func_0001AA80(int);
void func_00019F90(int);
void func_00019FD0(int);
void func_0006BD70();
void func_0006BCC0();
void func_0006BD40();
void func_0006BA30();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B590);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B600);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B618);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B64B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B694);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B6E4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B722);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B74B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B774);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B794);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B799);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B79E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B7A3);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B7B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B86C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B87D);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B902);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B909);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B90E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B974);
void func_0006B980(CcOwner *o)
{
    CcHook *h = o->field_3C;
    if (!h && (h = func_0001A010(o, 0xC)) != 0) {
        o->field_3C = h;
        h->field_4 = o->field_38;
        h->fn = func_0006B9C0;
        h->field_8 = o;
    }
    h->fn(h);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B9C0);
void func_0006BA10(ControlcObj *p)
{
    if (p->field_4->field_18 <= 0)
        p->field_0 = func_0006BA30;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BA30);
void func_0006BAF0(CcState *s)
{
    func_0001AA80(s->field_4);
    func_00019F90((int)s->field_8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BB10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BC10);
void func_0006BC90(CcState *s)
{
    s->field_C->field_5C = D_000C3364;
    s->field_C->field_68->field_B &= ~0x40;
    s->field_0 = func_0006BCC0;
    func_0006BCC0(s);
}

void func_0006BCC0(CcState *s)
{
    if (s->field_4 <= 0) {
        s->field_0 = func_0006BD40;
        s->field_4 = 0;
        return;
    }
    if (s->field_4 > 1) {
        s->field_8->field_68->field_B &= ~0x40;
        if (s->field_4 > 9)
            func_0001A6A0((int)s->field_8, 0x8E4, 8);
        else
            func_0001A6A0((int)s->field_8, 0x8E4, s->field_4 - 1);
    } else {
        s->field_8->field_68->field_B |= 0x40;
    }
}
void func_0006BD40(CcState *s)
{
    s->field_C->field_5C = D_000BB7F8;
    s->field_C->field_68->field_B |= 0x40;
    s->field_8->field_68->field_B |= 0x40;
    s->field_0 = func_0006BD70;
}

void func_0006BD70(CcState *s)
{
    if (s->field_4 > 0) {
        s->field_C->field_5C = D_000C3364;
        s->field_C->field_68->field_B &= ~0x40;
        s->field_0 = func_0006BCC0;
        func_0006BCC0(s);
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BD9F);
void func_0006BDF0(CcEntity *e, int arg1, int msg)
{
    CcState *s = e->state;
    if (msg == 0x5DA) {
        func_0001AA80(s->field_4);
        func_00019F90((int)s->field_0);
        func_00019FD0(s->field_8->field_C);
    }
}

void func_0006BE20(CcState *s)
{
    func_0001AA80(s->field_4);
    func_00019F90((int)s->field_0);
    func_00019FD0(s->field_8->field_C);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BE50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C090);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C0F0);
void func_0006C170(CcTur *s)
{
    s32 dir;
    if ((s->field_8->field_E0 == 2 || s->field_8->field_E0 == 8)
        && func_0006C2B0(s->field_8, s->field_8->field_E4, s->field_8->field_F0)
        && func_0001DBA0(s->field_8->field_14, s->field_8->field_E4)) {
        s->field_C = s->field_8->field_E4;
        s->field_30 = s->field_8->field_F0;
        func_0006C0F0(s);
        return;
    }
    if (func_0006C2B0(s->field_8, s->field_8->field_E8, s->field_8->field_F4)
        && func_0001DC00(s->field_8->field_14, s->field_8->field_E8)) {
        s->field_C = s->field_8->field_E8;
        s->field_30 = s->field_8->field_F4;
        func_0006C0F0(s);
        return;
    }
    dir = s->field_14;
    func_0001DE10(&dir, s->field_8->field_80, s->field_28->field_8);
    if (dir != s->field_14) {
        s->field_14 = dir;
        func_0001A5B0(s->field_4, s->field_28->field_18, D_000CD960[dir]);
    }
}
void func_0006C280(CcState *s)
{
    func_0001A6A0(s->field_4, s->field_28->field_18, D_000CD960[s->field_14]);
    s->field_10 = func_0006C170;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C2B0);
int func_0006C330(CcTaskEnt *e)
{
    CcTask *s = e->state;
    int r = s->field_10(s);
    if (s->field_18)
        s->field_18--;
    return r;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C3E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C420);
