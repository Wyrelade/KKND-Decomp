#ifndef MISSION_H
#define MISSION_H

#include "common.h"

typedef struct MsPos {
    u8 _pad0[0x10];
    s32 f10;                     /* x */
    s32 f14;                     /* y */
    u8 _pad18[0x70];
    s32 f88;                     /* set to 1 on every access */
} MsPos;

typedef struct MsNode {
    struct MsNode *next;
    u8 _pad4[0xc];
    s32 f10;
    s32 f14;
    u8 _pad18[0x44];
    MsPos *f5c;
    u8 _pad60[0x30];
    s32 f90;
} MsNode;

typedef struct MsCol {
    u8 _pad0[0x30];
    s32 f30;
} MsCol;
typedef struct MsSprC {
    u8 _pad0[0x68];
    MsCol *f68;
} MsSprC;
typedef struct MsSub {
    u8 _pad0[4];
    MsSprC *f4;
} MsSub;
typedef struct MsBld {
    u8 _pad0[0x14];
    s32 f14;
    u8 _pad18[4];
    MsSub *f1c;
    u8 _pad20[0x3c];
    MsSprC *f5c;
} MsBld;

#endif
