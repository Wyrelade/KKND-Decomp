/* network.c: 74 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "network.h"
extern int *D_000BB8B0;
extern char D_000B1164[];
void func_0004C080(char *, ...);
void NETZ_ReleaseAddr(void *);
void func_0001F5F0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00012550);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00012640);
int func_00012690(void)
{
    return 0x48;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001277C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013910);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013970);
void func_000139D0(void **p) { NETZ_ReleaseAddr(*p); *p = 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_000139F0);
INCLUDE_ASM("asm/DOS/nonmatchings", AddToAddrList);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013A60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013A90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013AE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013B20);
INCLUDE_ASM("asm/DOS/nonmatchings", InitAddrList);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013BC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00013CF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000141C0);
int GetServerAddr(u32 i) { int *t = D_000BB8B0; if (t == 0 || i >= 10) { func_0004C080(D_000B1164); return 0; } return t[i]; }

INCLUDE_ASM("asm/DOS/nonmatchings", GetServerName);
INCLUDE_ASM("asm/DOS/nonmatchings", FindLink);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000142D0);
INCLUDE_ASM("asm/DOS/nonmatchings", GetFreeColour);
INCLUDE_ASM("asm/DOS/nonmatchings", GetFreePlayer);
INCLUDE_ASM("asm/DOS/nonmatchings", FatalNetError);
void func_000144D0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000144E0);
int func_00014530(void)
{
    func_0001F5F0();
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00014550);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001470D);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001472B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014731);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014737);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014755);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000147A2);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000147DF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014893);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001495B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014976);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014980);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000149E8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014A0C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014BD6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014C05);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014C1A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014C26);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014C8F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014D18);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014D78);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014D9B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014E42);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00014EAC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001514F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001520C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015241);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015265);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001528F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000153BF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001543C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015569);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000155A7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000155B3);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000155DC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000156C7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001574A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001574B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015789);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000157C7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000157DB);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000157ED);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001583A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015893);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000158DA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015909);
