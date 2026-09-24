/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* tower.c: 59 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "tower.h"
void func_00047220();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00046CA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046DC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046E20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046F40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046FE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000470D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047160);
void func_00047200(void)
{
}

void func_00047210(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00047220);
void func_00047340(void)
{
    func_00047220();
}

void func_00047350(void)
{
    func_00047220();
}

void func_00047360(void)
{
    func_00047220();
}

void func_00047370(void)
{
    func_00047220();
}

void func_00047380(void)
{
    func_00047220();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00047390);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000474D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000475F0);
void func_00047650(void)
{
    func_0004DEC7(D_000D00C8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00047670);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000476E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047760);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047800);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047890);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047940);
void func_00047A20(TowerObj *a)
{
    a->field_C->field_34 = func_00047940;
    func_00042E30(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00047A40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047CE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047D30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00047DD0);
void func_00047E50(TowerObj *a)
{
    if (a->field_10 == 0x3a) func_0001A6A0(a->field_5C, 0x4d0, 2);
    else func_0001A6A0(a->field_5C, 0x3c8, 2);
    a->field_40 = func_00047DD0;
    func_0001A060(a->field_C, 0x80000000, 0x1e);
}

void func_00047EA0(TowerObj *a)
{
    if (a->field_10 == 0x3a) func_0001A6A0(a->field_5C, 0x4d0, 1);
    else func_0001A6A0(a->field_5C, 0x3c8, 1);
    a->field_40 = func_00047E50;
    func_0001A060(a->field_C, 0x80000000, 0x1e);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00047EF0);
void func_00048110(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00048120);
void func_00048220(TowerObj *a)
{
    a->field_C->field_34 = func_00048120;
    func_00042E30(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00048240);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000484D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048520);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048580);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000485E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000489B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048A10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048A70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048B50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048BF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048C90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048D90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048E70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00048F40);
void func_00049040(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00049050);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000490D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049140);
void func_000491B0(TowerObj *a)
{
    a->field_40 = func_00048D90;
    func_0001A060(a->field_C, 0x80000000, 5);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000491E0);
