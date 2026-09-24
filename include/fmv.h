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

#endif
