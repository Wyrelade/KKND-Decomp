/* nearmiss func_00050FF0 12 rp */
#include "common.h"
typedef struct { u8 _p[0x24]; s32 f24; s32 f28; } V;
typedef struct { u8 _p[8]; V *f8; } G;
typedef struct { u8 _p[4]; s32 f4; s32 f8; } S;
typedef struct { u8 _p[0x24]; s32 f24; s32 f28; s32 f2c; } O;
extern G *D_000B98D8;
extern S *D_000D0E1C;
void func_00050FF0(void *a, O *o)
{
    G *g;
    S *s;
    g = D_000B98D8;
    s = D_000D0E1C;
    o->f24 = g->f8->f24 - (s->f4 << 1);
    o->f28 = g->f8->f28 - (s->f8 << 1);
    o->f2c = 0x10000000;
}
