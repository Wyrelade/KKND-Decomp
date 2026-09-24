/* nearmiss func_0001F0E0 23 mul */
#include "common.h"
typedef struct { void (*f0)(void); void (*f4)(void); u8 _p[0x60]; } UnitHook;
extern s32 D_000BDBAC;
extern UnitHook D_000BDC14[];
void func_0001F0E0(void)
{
    s32 i = D_000BDBAC;
    if (D_000BDC14[i].f0) D_000BDC14[i].f0();
}
void func_0001F110(void)
{
    s32 i = D_000BDBAC;
    if (D_000BDC14[i].f4) D_000BDC14[i].f4();
}
