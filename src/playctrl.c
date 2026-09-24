/* playctrl.c: 35 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "playctrl.h"
/* decls */
extern s32 D_000BE7CC;
void func_0002F8E0();
void func_0004B600();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F200);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F810);
void func_0002F8A0(s32 a) { func_0002F8E0(a, 1); }
void func_0002F8C0(s32 a) { func_0002F8E0(a, 0); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F8E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F970);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FA00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FB80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FC00);
void func_0002FCA0(s32 a) { func_0004B600(a, 0x5f8, 0, 0xda000002); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FCC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FDE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FE30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FF70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002FFD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030090);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000300F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000301B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000303A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000306A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000306E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030790);
void func_000307B0(void) { D_000BE7CC = 1; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_000307D0);
void func_000307F0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00030800);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030A70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030B20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030B90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030BE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00030C60);
void func_00030D50(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00030D60);
