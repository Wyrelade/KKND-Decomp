#ifndef HEALTHBR_H
#define HEALTHBR_H

#include "common.h"

typedef struct HbSprite {
    u8 _pad0[0xb];
    u8 fb;
    void *fc;
} HbSprite;
typedef struct HbPos {
    u8 _pad0[0x10];
    s32 f10;
    s32 f14;
} HbPos;
typedef struct HbDef {
    u8 _pad0[0x10];
    s32 f10;                     /* max hit points */
} HbDef;

typedef struct HbUnit {
    u8 _pad0[0xc];
    s32 fc;
    s32 f10;
    s32 f14;
    struct HbDef *f18;
    u8 _pad1c[4];
    struct HbStat *f20;
    u8 _pad24[0x38];
    HbPos *f5c;
    u8 _pad60[0x34];
    s32 f94;
    u8 _pad98[4];
    s32 f9c;
    u8 _pada0[0x1e8];
    void (*f288)();
    s32 f28c;
    s32 f290;
    HbSprite *f294;
} HbUnit;

typedef struct HbBox {
    s32 f0;                      /* width */
    s32 f4;                      /* height */
    u8 f8;
    u8 f9[1];                    /* pixels */
} HbBox;
typedef struct HbStat {
    s32 f0;
    u8 _pad4[0x10];
    HbBox *f14;
    u8 _pad18[0x58];
    HbBox *f70;
} HbStat;

#endif
