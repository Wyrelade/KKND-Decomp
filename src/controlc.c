/* controlc.c: 45 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "controlc.h"
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B980);
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

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BCC0);
void func_0006BD40(CcState *s)
{
    s->field_C->field_5C = D_000BB7F8;
    s->field_C->field_68->field_B |= 0x40;
    s->field_8->field_68->field_B |= 0x40;
    s->field_0 = func_0006BD70;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006BD70);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C170);
void func_0006C280(CcState *s)
{
    func_0001A6A0(s->field_4, s->field_28->field_18, D_000CD960[s->field_14]);
    s->field_10 = func_0006C170;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C2B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C330);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C3E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C420);
