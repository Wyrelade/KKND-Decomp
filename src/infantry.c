/* infantry.c: 102 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "infantry.h"
void func_000462F0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DAF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DB50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DBD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DC40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DCA0);
void func_0003DEA0(InfUnit *a)
{
    a->field_80 = (a->field_80 + 0x40) & 0xff;
    func_0001A6A0(a->field_5C, a->field_18->field_38, D_000CD960[a->field_80]);
    func_0001A060(a->field_C, 0x10000000, 0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DEF0);
void func_0003DFC0(InfUnit *a)
{
    func_000514C0(a, a->field_AC, a->field_B0, a->field_A8);
    func_0001AA80(a->field_5C);
    func_00019F90(a->field_C);
    func_0001E270(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E000);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E1E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E350);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E4D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E5A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E670);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E7C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E850);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003E930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003EB20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003ED50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003EEA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003EFF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F050);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F160);
void func_0003F420(InfUnit *a)
{
    if (--a->field_254 == 0) a->field_40 = func_0003F160;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F440);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F870);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F8E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003F960);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003FB30);
void func_0003FBE0(InfUnit *a)
{
    func_0001C9E0(a, D_000B63AC);
    func_00042658(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003FC10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003FD70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040010);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000402B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040390);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000404D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000407E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040970);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040AC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040B90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00040D20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00041030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000411E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00041510);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00041880);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00041AA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000421C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042658);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000429B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042A10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042A80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042B20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042C00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042CB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042E30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00042FB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00043000);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00043180);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000436E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00043A50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00043B50);
s32 func_00043CF0(void)
{
    return D_000BD8F0 = (D_000BD8F0 * 0xc45 + 0x362b) & 0xffff;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00043D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00043E70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000440B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00044340);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000444C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00044540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00044610);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000446C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004485C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045110);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045290);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000456BC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000459E4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045BD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00045F00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046020);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000462F0);
void func_00046410(void)
{
    func_000462F0();
}

void func_00046420(InfState *a, int b)
{
    a->field_10 = (int (*)())func_00046920;
    a->field_C = (s32)a->field_8->field_E4;
    a->field_30 = a->field_8->field_E4->field_134;
}

void func_00046450(InfUnit *a, int b, int c)
{
    InfState *s = a->field_3C;
    if (s->field_8->field_90 == 0 && c == 0x5f3) {
        s->field_10 = (int (*)())func_00046920;
        s->field_C = (s32)s->field_8->field_E4;
        s->field_30 = s->field_8->field_E4->field_134;
    }
}

void func_000464A0(void)
{
}

void func_000464B0(InfFx *a)
{
    func_0001A6A0(a->field_4, a->field_28->field_18, D_000CD960[a->field_14]);
    a->field_10 = (int (*)())func_000464F0;
    func_0001A060(a->field_0, 0x80000000, 0xf);
}

void func_000464F0(InfFx *a)
{
    if (!func_0001DE10(&a->field_14, 0xa0, a->field_28->field_8)) a->field_10 = (int (*)())func_00046540;
    func_0001A6A0(a->field_4, a->field_28->field_18, D_000CD960[a->field_14]);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00046540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000465A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000466A0);
void func_000467B0(InfFx *a)
{
    if (a->field_8->field_10 != 0x38 && a->field_8->field_10 != 0x39)
        func_0001A6A0(a->field_4, a->field_28->field_1C, D_000CD960[a->field_14]);
    a->field_10 = (int (*)())func_000466A0;
    a->field_0->field_27 &= 0xef;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00046800);
void func_000468D0(InfFx *a)
{
    if (a->field_8->field_10 == 0x39) func_0001A6A0(a->field_4, a->field_28->field_1C, D_000CD960[a->field_14]);
    else func_0001A6A0(a->field_4, a->field_28->field_18, D_000CD960[a->field_14]);
    a->field_10 = (int (*)())func_00046800;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00046920);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000469D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046A40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046C00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046C70);
