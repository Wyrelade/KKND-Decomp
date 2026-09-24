#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "common.h"

/* List node (same layout as the sound list node); D_000CDE94 is the sentinel head. */
typedef struct LsNode {
    struct LsNode *next;
    u8 _pad4[0x130];
    s32 f134;                    /* id */
} LsNode;

typedef struct LsObj {
    u8 _pad0[0x90];
    s32 f90;
    u8 _pad94[0xa0];
    s32 f134;
} LsObj;

typedef struct LsTask {
    u8 _pad0[0x14];
    s32 f14;
    u8 _pad18[8];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    u8 _pad30[4];
    s32 f34;
} LsTask;
typedef struct LsTaskSave {
    s32 f0;
    u32 f4;
    u32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
} LsTaskSave;

#endif
