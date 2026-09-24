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
typedef struct HbUnit {
    u8 _pad0[0x10];
    s32 f10;
    u8 _pad14[0x48];
    HbPos *f5c;
    u8 _pad60[0x228];
    void (*f288)();
    s32 f28c;
    s32 f290;
    HbSprite *f294;
} HbUnit;

#endif
