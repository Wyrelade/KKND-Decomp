#ifndef FMV_H
#define FMV_H

#include "common.h"

typedef struct FmvObj {
    u8 _pad0[0x8];
    s32 field_8;
} FmvObj;

/* Task handle returned by func_0001A270 (tasks.c); only the flag byte is used here. */
typedef struct FmvTask {
    u8 _pad0[0x1C];
    u8 field_1C;
} FmvTask;

/* Start tick / elapsed pair used by the playback timer. */
typedef struct FmvTimer {
    s32 field_0;
    s32 field_4;
} FmvTimer;

/* Source image descriptor passed to func_00020600. */
typedef struct FmvSrc {
    u8 _pad0[0x1C];
    s32 field_1C;
    u8 _pad20[0x20];
    s32 field_40;
} FmvSrc;

/* View/blit record filled by func_00020600. */
typedef struct FmvView {
    u8 _pad0[0x18];
    s32 *field_18;
    u8 _pad1C[0x8];
    s32 field_24;
    s32 field_28;
    s32 field_2C;
} FmvView;

/* Doubly linked sort node (next, prev, key at 0x2C). */
typedef struct FmvNode {
    struct FmvNode *next;
    struct FmvNode *prev;
    u8 _pad8[0x24];
    s32 key;
} FmvNode;

#endif
