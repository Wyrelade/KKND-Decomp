#ifndef UNCOVER_H
#define UNCOVER_H

#include "common.h"

typedef struct UncEnt {
    u8 _pad0[0x40];
    void (*f40)(struct UncEnt *);
} UncEnt;

typedef struct UncDef {
    u8 _pad0[0x4c];
    s32 f4c;                     /* 0x1000 = uses the uncover path */
} UncDef;

typedef struct UncPos {
    u8 _pad0[0x10];
    s32 f10;                     /* x */
    s32 f14;                     /* y */
    u8 _pad18[0x70];
    s32 f88;
} UncPos;

typedef struct UncUnit {
    u8 _pad0[0x18];
    UncDef *f18;
    u8 _pad1c[0x40];
    UncPos *f5c;
    u8 _pad60[0x48];
    s32 fa8;
    s32 fac;
    s32 fb0;
} UncUnit;

/* List node; D_000D1320 is the sentinel head (func_000520E0). */
typedef struct UncNode {
    struct UncNode *next;
    s32 f4;
    s32 f8;                      /* key */
    s32 fc;                      /* value */
} UncNode;

#endif
