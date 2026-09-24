/* infantry.c: 102 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "infantry.h"
void func_000462F0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DAF0);
void func_0003DB50(InfBase *a, int b, int msg, int d)
{
    InfUnit *s = a->field_3C;
    if (s->field_90 == 0) {
        switch (msg) {
        case 0x5e7: func_0005D2B0(s, d); break;
        case 0x5e8: func_0005D290(s, d); break;
        case 0x5eb: func_0006C360(s, d); break;
        case 0x5df: func_0003D170(s, d); break;
        case 0x5f4: func_0003D660(s, d); break;
        }
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DBD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DC40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003DCA0);
void func_0003DEA0(InfUnit *a)
{
    a->field_80 = (a->field_80 + 0x40) & 0xff;
    func_0001A6A0(a->field_5C, a->field_18->field_38, D_000CD960[a->field_80]);
    func_0001A060(a->field_C, 0x10000000, 0);
}

void func_0003DEF0(InfUnit *a)
{
    func_0001C9C0(D_000B662C, a->field_10, a->field_134, a->field_5C->field_10, a->field_5C->field_14);
    func_0001C9F0(D_000B6648);
    func_0001C9F0(D_000B666C);
    func_0001C9F0(D_000B6688);
    func_0001A6A0(a->field_5C, a->field_18->field_38, D_000CD960[a->field_80]);
    a->field_40 = func_0003DEA0;
    a->field_90 = 1;
    func_0004B600(a->field_C, 0x5e8, a, 0x9876);
    func_000514C0(a, a->field_AC, a->field_B0, a->field_A8);
    a->field_C->field_34 = func_0003DBD0;
}
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
void func_0003E4D0(InfUnit *a)
{
    a->field_5C->field_1C = 0;
    a->field_5C->field_20 = 0;
    func_0001A6A0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    if (!func_0001DE10(&a->field_80, 0xa0, a->field_18->field_1C)) {
        a->field_5C->field_1C = 0x40;
        a->field_5C->field_20 = -0x40;
        func_0001A6A0(a->field_5C, a->field_18->field_38, D_000CD960[a->field_80]);
        a->field_12C = 0x64;
        a->field_E0 = 0;
        a->field_40 = func_0003E5A0;
        a->field_E4->field_20->field_8 = 1;
        a->field_58 = a->field_C->field_34;
    }
    func_0001A060(a->field_C, 0x80000000, 1);
}
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
void func_00042C00(InfUnit *a)
{
    s32 r;
    r = (D_000BD8F0 * 0xc45 + 0x362b) & 0xffff; D_000BD8F0 = r; r &= 0x7f;
    if (r < 0x46) {
        if (a->field_18->field_34 != -1) {
            func_0001A6A0(a->field_5C, a->field_18->field_34, D_000CD960[a->field_80]);
            a->field_5C->field_60 = 0;
        }
    } else {
        a->field_80 = (r < 0x64 ? a->field_80 + 0x20 : a->field_80 - 0x20) & 0xff;
        func_0001A5B0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    }
    a->field_40 = func_00042E30;
    func_0001A060(a->field_C, 0x80000000, 0x50);
}
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
void func_000469D0(InfFx *a)
{
    a->field_30 = 0;
    func_0001A6A0(a->field_4, a->field_28->field_18, D_000CD960[a->field_14]);
    if (func_00046A40(a)) {
        a->field_10 = (int (*)())func_00046920;
        func_0001A060(a->field_0, 0x80000000, 1);
    }
    func_0001A060(a->field_0, 0x80000000, 0x5a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046A40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00046C00);
int func_00046C70(InfBase *a)
{
    InfState *s = (InfState *)a->field_3C;
    int r = s->field_10(s);
    if (s->field_18) s->field_18--;
    return r;
}
