/* netzutil.c: 35 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "netzutil.h"
/* decls */
extern NzRegs D_000CFA88;
extern char D_000BDF60[];
void func_0004C163(void *, int, int, char *, int, int);
void func_00038244(int, NzRegs *, NzRegs *, NzSregs *);
extern NzPeer *D_000CFB38;
extern int D_000CFB30;
extern int D_000BE3C4;
extern int D_000BDA4C;
void func_0001BD80(int, int, int, int, int);
extern int D_000BDF90;
extern int D_000BB290;
extern NzPlayerFlags D_000C310D[];
extern int D_000BEAF0;
extern NzPeer *D_000CFB6C;
int func_0002A3C0(void);
void func_0002AB60(int, int, int);
extern int *D_000CC7A0;
extern NetzGame *D_000CFB3C;
extern NetzEvent *D_000BDF7C;
extern NetzPacket *D_000BDF74;
extern char D_000B2FE0[];
extern char D_000B2EB0[];
extern void (*D_000BDBB4)(int, char *, ...);
int NETZ_CancelEvent(NetzEvent *);
int func_000299A0(NetzEvent *);
void func_00050DF0(void);
void func_0004B670(int, int, int, int);
int func_000267D0(void);
NetzPlayer *func_0002A070(void);
void NETZ_Hangup(int);
int func_00029EC0(int);

NzRegs *func_00029650(u8 n, int a, int b, int c, int d)
{
    NzSregs s;
    func_0004C163(&D_000CFA88, 0, 0x1C, D_000BDF60, 0x1FA, 4);
    func_0004C163(&s, 0, 0xC, D_000BDF60, 0x1FB, 4);
    D_000CFA88.eax = a;
    D_000CFA88.ebx = b;
    D_000CFA88.ecx = c;
    D_000CFA88.edx = d;
    func_00038244(n, &D_000CFA88, &D_000CFA88, &s);
    return &D_000CFA88;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000296E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000297B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029860);
void func_00029910(void)
{
    if (D_000BDF7C)
        do
            NETZ_CancelEvent(D_000BDF7C);
        while (D_000BDF7C);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029940);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029970);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000299A0);
int NETZ_CancelEvent(NetzEvent *e)
{
    if (e->field_0 == 0) {
        D_000BDBB4(0x45, D_000B2FE0, e);
        return 0xFE000B;
    }
    return func_000299A0(e);
}

INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_ProcessEvents);
INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_AddEvent);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029BD0);
INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_InitEventPool);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029CE0);
INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_InitPacketPool);
void NETZ_ReleasePacket(NetzPacket *p)
{
    if (p->field_0 == 0) {
        D_000BDBB4(0x45, D_000B2EB0, p);
    } else {
        NetzPacket *t = D_000BDF74;
        p->field_0 = 0;
        D_000BDF74 = p;
        p->field_4 = t;
    }
}

INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_GrabPacket);
int func_00029E90(void) { int i; for (i = 0; i < 8; i++) { NETZ_Hangup(i); func_00029EC0(i); } return 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029EC0);
INCLUDE_ASM("asm/DOS/nonmatchings", NETZ_OpenLink);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029FB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029FF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A020);
NetzPlayer *func_0002A070(void)
{
    NetzPlayer *p = D_000CFB3C->field_24;
    if (D_000CC7A0[p->field_C] + 0x7BC == p->field_4C)
        return 0;
    return p;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A0A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A120);
void func_0002A190(void)
{
    if (D_000BDF90) {
        if (!func_0002A3C0())
            func_0001BD80(0x42, 0, D_000BE3C4, 0, 0);
        else
            func_0001BD80(0x88, 0, D_000BE3C4, 0, 0);
        if (D_000BDF90) {
            func_0004B670(0, 0x5EA, 0, D_000CFB38->field_8);
            func_0004B670(0, 0x5E7, 0, D_000CFB30);
        }
        D_000BDA4C++;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A270);
void func_0002A2C0(void)
{
    if (!D_000BDF90 && !(D_000C310D[D_000BB290].field_0 & 0x20)) {
        D_000BDF90 = 1;
        if (func_0002A3C0())
            func_0002AB60(D_000BEAF0, 0x2B, 0x8BC);
        else
            func_0002AB60(D_000BEAF0, 0x2C, 0x8BC);
        func_0004B670(0, 0x5EA, 0, D_000CFB6C->field_8);
    }
}
void func_0002A330(void)
{
}

void func_0002A340(void)
{
}

void func_0002A350(void)
{
    func_00050DF0();
    func_0004B670(0, 0x60C, 0, D_000CFB3C->field_8);
}

void func_0002A380(void)
{
    if (func_000267D0() || !func_0002A070())
        func_0004B670(0, 0x5EA, 0, D_000CFB3C->field_8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A3C0);
