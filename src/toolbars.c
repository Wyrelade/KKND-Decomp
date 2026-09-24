/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* toolbars.c: 60 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "toolbars.h"
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
void func_0002C300(int, int, void (*)(), int, int, int, int, int);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C280);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C300);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C450);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002C740);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CC20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CCD0);
