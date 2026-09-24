/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* sound.c: 96 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include <conio.h>
#include "sound.h"
/* decls */
void func_00054D24();
extern s32 D_000CC9D8;
extern s32 D_000BDA34;
extern s32 D_000BD858;
extern s32 D_000CD450;
void func_0001C0F0();
void func_0004DEC7();
unsigned snd_inp(unsigned port);
#pragma aux snd_inp = 0x29 0xc0 0xec parm [edx] value [eax] modify exact [eax];
unsigned snd_outp(unsigned port, unsigned v);
#pragma aux snd_outp = 0xee parm [edx] [eax] value [eax] modify exact [];
extern s32 D_000CDD74;
extern SndNode D_000CDE94;
extern SndNode *D_000CDD70;
extern s32 D_000BD8EC;
extern s32 D_000BD8E8;
void func_0004B670();
extern SndList D_000CC920;
extern s32 D_000BD860;
extern s32 D_000BD85C;
void func_0001C1B0();
extern s32 D_000CDD7C;
extern char D_000BD850[];
void func_0004C09C();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B7E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B850);
void func_0001B8A0(void)
{
    func_0001C1B0(&D_000CC920);
    func_0001C330(&D_000CC920);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B8C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B940);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001B9B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BA50);
void func_0001BA90(void)
{
}

void func_0001BAA0(void)
{
}

void func_0001BAB0(void)
{
}

void func_0001BAC0(s32 x)
{
    func_00054D24((s16)(x >> 7));
}

void func_0001BAD0(void)
{
}

void func_0001BAE0(void)
{
}

void func_0001BAF0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BB00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BB50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BBF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BC50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BD80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BE70);
int func_0001BF60(void)
{
    if (D_000BD860 != 0 && D_000BD85C != 0) return 1;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001BF90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C020);
void func_0001C070(s32 *p)
{
    *p = 1;
    func_0001C0F0(p, 0);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C090);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C0F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C1B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C200);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C260);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C2B0);
void func_0001C330(SndList *s)
{
    SndSlot *p;
    u32 n;

    s->f4 = 0;
    s->fC = -1;
    s->f10 = 0;
    s->f0 = 0;
    for (n = s->f8, p = s->f14; n != 0; n--, p++)
        p->f0 = 0;
}
void func_0001C370(SndList *s)
{
    SndSlot *p;
    u32 n;

    if (s->f14 != 0) {
        s->f4 = 0;
        s->fC = -1;
        s->f10 = 0;
        s->f0 = 0;
        for (n = s->f8, p = s->f14; n != 0; n--, p++)
            p->f0 = 0;
        func_0004C09C(s->f14, D_000BD850, 0xb4);
        s->f14 = 0;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C3E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C420);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C460);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C4E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C520);
void func_0001C540(void) { D_000BD858 = 1; }
void func_0001C560(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C570);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C600);
s32 func_0001C740(void) { return D_000CC9D8; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C7A0);
void func_0001C7D0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001C7E0);
void func_0001C9A0(void)
{
}

void func_0001C9B0(void)
{
}

void func_0001C9C0(void)
{
}

void func_0001C9D0(void)
{
}

void func_0001C9E0(void)
{
}

void func_0001C9F0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CA00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CA50);
void func_0001CAD0(int idx, int *r, int *g, int *b)
{
    snd_outp(0x3c8, idx);
    *r = snd_inp(0x3c9);
    *g = snd_inp(0x3c9);
    *b = snd_inp(0x3c9);
}
void func_0001CB00(int idx, int r, int g, int b)
{
    outp(0x3c8, idx);
    outp(0x3c9, r);
    outp(0x3c9, g);
    outp(0x3c9, b);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CB30);
s32 func_0001CB70(void) { return D_000BD8EC = (D_000BD8EC * 0xc45 + 0x362b) & 0xffff; }
s32 func_0001CB90(void) { return D_000BD8E8 = (D_000BD8E8 * 0xc45 + 0x362b) & 0xffff; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CBB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CBF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CCC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CDC4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CE34);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CEA4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001CF40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D160);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D1D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D240);
int func_0001D2E0(S2E0 *p, s32 a, s32 b)
{
    if ((p->f0 & 0x40) && a != p->f2 && b != p->f2) return 0;
    return 1;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D410);
void func_0001D690(void) { func_0004DEC7(D_000CD450); }
void func_0001D6B0(void) { D_000BDA34++; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001D6C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DA20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DBA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DC00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DC50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DCA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DE10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DEE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001DF30);
void func_0001DF80(s32 a) { func_0004B670(0, 0x5e8, a, D_000CDD74); }
void func_0001DFB0(SndObjC *a, s32 b)
{
    if (a) func_0004B670(a->fC, 0x5e8, b, D_000CDD7C);
    else func_0004B670(0, 0x5e8, b, D_000CDD7C);
}
void func_0001DFF0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E000);
void func_0001E030(void) { D_000CDD70 = D_000CDE94.next; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E050);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E0E0);
SndNode *func_0001E110(s32 key)
{
    SndNode *p;

    for (p = D_000CDE94.next; p != &D_000CDE94; p = p->next)
        if (key == p->f134) return p;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E140);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E1C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E1F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E270);
