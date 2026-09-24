/* healthbr.c: 48 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "healthbr.h"
/* decls */
extern s32 D_000D1D4C;
void func_00062430();
void func_0005D220();
HbSprite *func_00020870();
extern s32 D_000D1ED0;
extern s32 D_000BDBAC;
extern char D_000B76DC[];
void func_0004DEC7();
void func_0005E450();
void func_0005E2F0();
unsigned hb_inp(unsigned port);
#pragma aux hb_inp = 0x29 0xc0 0xec parm [edx] value [eax] modify exact [eax];
extern u8 D_000D1EE1;
extern u8 D_000D1EE0;
extern s32 D_000D1EFE;
#include <conio.h>
extern s32 D_000D1EF6;
void func_00075D42();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005C9F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005CA90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005CC70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005CE50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005CEF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005CF90);
void func_0005D010(HbUnit *u)
{
    HbSprite *s;
    u->f28c = 0;
    u->f288 = func_00062430;
    u->f290 = D_000D1D4C;
    s = func_00020870(u->f5c, func_0005D220);
    u->f294 = s;
    s->fc = u;
    u->f294->fb |= 0x40;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D060);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D0F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D150);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D1C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D290);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D2B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D2D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D370);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D580);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D7F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005D990);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DB20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DC00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DD30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DD90);
void func_0005DF20(void) { func_0004DEC7(D_000D1ED0); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DF40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005DFA4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E07D);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E07F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E091);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E0AD);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E0EC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E0FF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E103);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E110);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E150);
int func_0005E180(void)
{
    if (D_000BDBAC == 3) func_0005E2F0();
    return 0;
}
int func_0005E1A0(void)
{
    if (D_000D1EE0 && D_000D1EE1) return hb_inp(D_000D1EFE) & 0x80;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E1D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E200);
int func_0005E230(void)
{
    if (D_000D1EE0) return hb_inp(D_000D1EFE) & 0x10;
    return 0;
}
void func_0005E260(void)
{
    outp(D_000D1EF6, 0);
    func_00075D42(100);
    outp(D_000D1EF6, 2);
    func_00075D42(100);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E290);
int func_0005E2D0(void)
{
    if (D_000D1EE1) return hb_inp(D_000D1EFE);
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E2F0);
void func_0005E340(void) { func_0005E450(D_000B76DC); }
