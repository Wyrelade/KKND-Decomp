/* nipx.c: 25 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "nipx.h"
/* decls */
extern IpxEcb *D_000C59D8;
extern IpxEcb *D_000C59DC;
RmRegs *func_00070980(int);
extern u16 D_000C59EC;
extern s32 D_000C59F0;
void func_00070300(char *, int);
extern char D_000B7CE4[];
extern u16 D_000D70D4;
s16 func_00070AD0(int, int, int, u16, int, int);

INCLUDE_ASM("asm/DOS/nonmatchings", GrabFreeECB);
IpxEcb *func_000705C0(void)
{
    IpxEcb *p = D_000C59D8;
    IpxEcb *r = 0;
    while (p) {
        if (p->field_0 && p->field_4 == 0 && p->field_E == 0) {
            r = p;
            break;
        }
        p = p->field_156;
    }
    if (p && p->field_156)
        D_000C59D8 = p->field_156;
    else
        D_000C59D8 = D_000C59DC;
    return r;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070620);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070650);
INCLUDE_ASM("asm/DOS/nonmatchings", nIPX_RelinguishControl);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000706F0);
/* 16-bit byte swap (network order) */
u32 func_000707E0(u32 x)
{
    return (x << 8) + ((x & 0xFF00) >> 8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", IPX_Send);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070980);
INCLUDE_ASM("asm/DOS/nonmatchings", IPX_Listen);
void func_00070AA0(u16 a)
{
    func_00070AD0(0, 1, 0, a, 0, 0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070AD0);
u16 func_00070BF0(u16 s)
{
    if (func_00070AD0(0, 0, 0, s, 0, 0)) {
        func_00070300(D_000B7CE4, 0);
        return 0;
    }
    return D_000D70D4;
}
int func_00070C30(void)
{
    RmRegs *r = func_00070980(0x7A00);
    u16 es;
    s32 di;
    if ((r->eax & 0xFF) != 0xFF)
        return 1;
    es = r->es;
    di = r->edi;
    D_000C59EC = es;
    D_000C59F0 = di;
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070C70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070DF6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E47);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E99);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070F59);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070F98);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070FCE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0007105E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00071079);
