#ifndef SOUND_H
#define SOUND_H

#include "common.h"

/* Sound channel slot (0x38 bytes), element of SndList.f14 (func_0001C260 fills it). */
typedef struct SndSlot {
    s32 f0;                      /* in use */
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;                     /* handle passed to func_0001BB50 */
    s32 f14;
    u8 _pad18[0x20];
} SndSlot;

typedef struct SndList {
    s32 f0;
    s32 f4;                      /* used slots */
    u32 f8;                      /* capacity */
    u32 fC;                      /* current slot, -1 = none */
    s32 f10;
    SndSlot *f14;
} SndList;

typedef struct { u8 f0; u8 f1; s32 f2; } S2E0;

typedef struct SndPos {
    u8 _pad0[0x10];
    s32 f10;
    s32 f14;
    u8 _pad18[0x70];
    s32 f88;
} SndPos;

typedef struct SndDef { u8 _pad0[0x1c]; s32 f1c; } SndDef;

typedef struct SndEnt {
    u8 _pad0[0x18];
    SndDef *f18;
    u8 _pad1c[0x40];
    SndPos *f5c;
    u8 _pad60[0x20];
    u8 f80[4];
} SndEnt;

typedef struct { u8 _pad[0xc]; s32 fC; } SndObjC;

/* Doubly-used list node; D_000CDE94 is the sentinel head (func_0001E110). */
typedef struct SndNode {
    struct SndNode *next;
    u8 _pad4[0x130];
    s32 f134;                    /* key */
} SndNode;

typedef struct { u8 _pad[0x4C]; u32 field_4C; } SndCfg;
typedef struct { u8 _pad[0x18]; SndCfg *field_18; } SndObj;

typedef struct SndReq { u8 _pad[0x10]; s32 f10; s32 f14; } SndReq;

#endif
