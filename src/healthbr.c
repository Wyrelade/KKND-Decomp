/* healthbr.c: 48 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "healthbr.h"
/* decls */
extern char D_000C420A[];
void func_0004C163();
void func_0005D990();
void func_0005DB20();
extern char D_000B7320[];
void func_0005D060();
void func_0005D370();
extern char D_000B7344[];
HbBox *func_0001A010();
void func_0001C9F0(char *fmt, ...);
void func_0005D0F0();
void func_0005D2D0();
void hb_outpb(unsigned port, u8 v);
#pragma aux hb_outpb = 0xee parm [edx] [al] modify exact [];
void hb_cli(void);
#pragma aux hb_cli = 0xfa modify exact [];
void hb_sti(void);
#pragma aux hb_sti = 0xfb 0xfc modify exact [];
void hb_outp(unsigned port, unsigned v);
#pragma aux hb_outp = 0xee parm [edx] [eax] modify exact [];
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
void func_0005CE50(HbUnit *u)
{
    HbStat *st = u->f20;
    HbSprite *s;
    st->f70 = func_0001A010(u->fc, 0x12a);
    if (st->f70 == 0) {
        func_0001C9F0(D_000B7344);
        return;
    }
    st->f70->f0 = 0x20;
    st->f70->f4 = 9;
    st->f70->f8 = 0;
    u->f290 = (s32)st->f70;
    u->f28c = 0;
    u->f288 = func_00062430;
    s = func_00020870(u->f5c, func_0005D0F0);
    u->f294 = s;
    s->fc = u;
    func_0005D2D0(u);
    u->f294->fb |= 0x40;
}
void func_0005CEF0(HbUnit *u)
{
    HbStat *st = u->f20;
    HbSprite *s;
    st->f14 = func_0001A010(u->fc, 0x3e8);
    if (st->f14 == 0) {
        func_0001C9F0(D_000B7320);
        return;
    }
    st->f14->f0 = 0x42;
    st->f14->f4 = 0xf;
    st->f14->f8 = 0;
    u->f290 = (s32)st->f14;
    u->f28c = 0;
    u->f288 = func_00062430;
    s = func_00020870(u->f5c, func_0005D060);
    u->f294 = s;
    s->fc = u;
    func_0005D370(u);
    u->f294->fb |= 0x40;
}
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
void func_0005D2D0(HbUnit *u)
{
    u8 *p = u->f20->f70->f9;
    int i;
    func_0004C163(p, 1, 0x120, D_000C420A, 0x1cc, 4);
    func_0004C163(p, 0xa6, 0x20, D_000C420A, 0x1cd, 4);
    func_0004C163(p + 0x100, 0xa4, 0x20, D_000C420A, 0x1ce, 4);
    p += 0x20;
    for (i = 0; i < 7; i++) {
        p[0] = 0xa6;
        p[0x1f] = 0xa4;
        p += 0x20;
    }
    func_0005D990(u);
    func_0005DB20(u);
}
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
void func_0005E1D0(void)
{
    if (D_000D1EE0) {
        hb_cli();
        hb_outp(D_000D1EF6, hb_inp(D_000D1EF6) | 1);
        hb_sti();
    }
}
void func_0005E200(void)
{
    if (D_000D1EE0) {
        hb_cli();
        hb_outpb(D_000D1EF6, hb_inp(D_000D1EF6) & 0xfe);
        hb_sti();
    }
}
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
