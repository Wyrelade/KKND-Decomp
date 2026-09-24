/* nearmiss func_0002F810 10 sched */
#include "common.h"
#include "playctrl.h"
#include "super.h"
extern char D_000B4B1C[];
s32 func_0002F810(s32 a, u16 b)
{
    SuperSub *s;
    SuperEnt *e;
    s32 r;
    s = D_000CFFD8;
    s->field_18 = 0;
    s->field_1C = 6;
    func_00032680(s, D_000B4B1C, 0);
    s = D_000CFFD8;
    s->field_18 = 0;
    func_00032680(s, a, 0);
    D_000CFFDC->field_88 = 1;
    r = func_00032650(D_000CFFD8, b, 6);
    e = D_000CFFDC;
    e->field_88 = 1;
    e->field_14 = 0xc200;
    e->field_10 = r << 8;
    return a;
}
