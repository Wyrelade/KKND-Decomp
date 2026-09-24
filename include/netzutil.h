#ifndef NETZUTIL_H
#define NETZUTIL_H

#include "common.h"

typedef struct NetzEvent {
    s32 field_0;
    struct NetzEvent *field_4;
    u8 _pad8[4];
    u8 field_C;
    u8 _padD[0x1E];
    s32 field_2B;
} NetzEvent;

typedef struct NetzPacket {
    s32 field_0;
    struct NetzPacket *field_4;
    u8 field_8[4];
} NetzPacket;

typedef struct NetzPlayer {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x3C];
    s32 field_4C;
} NetzPlayer;

typedef struct NetzGame {
    u8 _pad0[8];
    s32 field_8;
    u8 _padC[0x18];
    NetzPlayer *field_24;
} NetzGame;

#endif
