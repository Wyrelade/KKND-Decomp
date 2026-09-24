/* key2.c: 96 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "key2.h"
/* decls */
int func_0006DD10(int a, int b, int c, int d, Key2Req *r);
int func_0006D5B0(int a, int b, int c, int d, Key2Req *r);
extern NetAddr *D_000D7080;
extern char D_000B7E48[];
extern void (*D_000BDBB4)(int, char *, ...);

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006C710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CB25);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CB4A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CB94);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CBB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CBBE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CBF6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CC1B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CC68);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CC9C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CCAF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CCF7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CD90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CD93);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CD96);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CD9C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CD9F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CDA2);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CDBD);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CDD5);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CEC5);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CF9C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CFAF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006CFFE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D049);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D098);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D155);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D240);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D400);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006D5B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006DA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006DD10);
int func_0006DE00(int a, int b, int c, int d, Key2Req *r)
{
    switch (r->field_18->field_4C) {
    case 0x80:
    case 0x200:
        return func_0006DD10(a, b, c, d, r);
    case 0x1000:
        return func_0006D5B0(a, b, c, d, r);
    }
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006DE50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006DF40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E0D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E110);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E320);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E530);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E6D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E760);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006E910);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006EB70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006EC80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006EF0F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006EF91);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F1B3);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F28C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F2C1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F347);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F435);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F493);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F4D6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F5BC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006F89A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FA92);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FAB9);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FADC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FB20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FB33);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FB63);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FB88);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FB96);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FBCF);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FC56);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FC6A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FC76);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FCD5);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FD4C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FDDD);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FDF1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FE2E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FE78);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FEA4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FEB9);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FEBA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FEC8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FEEC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FF06);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FF23);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FF80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FF9E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006FFF3);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070008);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000700CB);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0007021F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0007027A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000702A6);
void func_00070300(char *msg, int v)
{
    D_000BDBB4(0x45, D_000B7E48, msg, v);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070320);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070370);
INCLUDE_ASM("asm/DOS/nonmatchings", GetLocalAddr);
int func_00070400(u8 *a)
{
    return wc10_memcmp(a, D_000D7080->field_4, 6) == 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070440);
INCLUDE_ASM("asm/DOS/nonmatchings", InitECBPool);
