/* netipx.c: 102 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "netipx.h"
extern char D_000D07E0[];
extern int D_000C2120;
extern int D_000BDB94;
extern int D_000BDB98;
extern char D_000C2108[];
extern char D_000D0941[];
extern char D_000D0930[];
extern u8 D_000BE8EC;
extern u8 D_000D0940;
extern int D_000C211E;
int func_0004D010(int, char *);
void func_00070800(char *, char *, int);
void func_0004D47C(char *, int, int, char *, int, int);
int func_0004C2E0(void);
void func_0004D060(int, int, char *, int);
extern int D_000D0768;
int func_00070BF0();
void func_00070400();
void func_00070AA0();
void func_00070C30();

void func_0004C1E0(void)
{
    int a, b;
    if ((a = D_000BDB94) != 0 && (b = D_000BDB98) != 0)
        func_0004D47C(D_000D0941, a, b, D_000C2108, 0x489, 0x20);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C250);
void func_0004C2C0(void)
{
}

s32 func_0004C2D0(NetIpxPacket *p)
{
    return p->field_2F;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C2E0);
void func_0004C410(int a, int b)
{
    D_000C2120 = func_0004C2E0();
    D_000D0940 = D_000BE8EC;
    func_0004D060(D_000C211E >> 16, 0x1F, D_000D0930, 0x31);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C4F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C580);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C5F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C690);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C6F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C7B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C7D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C810);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004C9B8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CD20);
int func_0004CD50(void)
{
    return 0;
}

int func_0004CD60(void)
{
    return 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CD70);
void func_0004CDA0(void) { func_00070400(D_000D0768); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CDC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CDE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CE20);
void func_0004CE70(int a)
{
    char buf[8];
    if (!func_0004D010(a, buf))
        func_00070800(buf, D_000D07E0, 0x6E);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CEA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004CF20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D010);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D060);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D1B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D240);
void func_0004D2B0(s32 a)
{
    func_00070AA0((u16)a);
}

int func_0004D2D0(u16 a) { func_00070BF0(a); return 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D2F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D330);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D3F0);
void func_0004D470(void)
{
    func_00070C30();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D47C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D4AA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D4E8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D523);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D57E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D59A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D5D1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D5F6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D612);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D678);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D6DA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D6EE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D6FE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D70E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D796);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7AF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7D7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7D8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7E6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7EB);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7F7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D7FE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D80E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D821);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D8C9);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D920);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004D962);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DA5E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DA90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DB07);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DB26);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DBAF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DBDE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DC89);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DC8F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DD4E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DD7E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DDBF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DDF1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DEC7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DF4D);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DF52);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DFAB);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DFBA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004DFF6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E01B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E085);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E171);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E24A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E2B1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E2C4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E2D9);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E2F8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E3B8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E6CD);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E6E6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E7D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E920);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004E990);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EA70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EB10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EB90);
