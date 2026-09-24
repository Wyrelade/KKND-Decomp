#ifndef UNITS_H
#define UNITS_H

#include "common.h"

typedef struct UnA { u8 _pad0[0x7c]; s32 f7c; } UnA;
typedef struct UnB { u8 _pad0[0xc]; s32 fc; u8 _pad10[8]; s32 f18; } UnB;

/* Unit controller: +0x10 is the state handler (func_0001EC30 installs func_0001EBE0). */
typedef struct UnS {
    s32 f0;
    UnA *f4;
    UnB *f8;
    u8 _padc[4];
    void (*f10)(struct UnS *);
    s32 f14;                     /* index into D_000CD960 */
    u8 _pad18[0x10];
    UnB *f28;
} UnS;

#endif
