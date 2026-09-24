#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "common.h"

/* List node (same layout as the sound list node); D_000CDE94 is the sentinel head. */
typedef struct LsNode {
    struct LsNode *next;
    u8 _pad4[0x130];
    s32 f134;                    /* id */
} LsNode;

#endif
