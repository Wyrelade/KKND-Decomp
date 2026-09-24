#ifndef CRTGEN_H
#define CRTGEN_H

#include "common.h"

typedef struct CgOwner {
    u8 _pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    u8 _pad1c[0x54];
    void *f70;
    void *f74;
    struct CgNode *f78;
} CgOwner;
typedef struct CgNode {
    struct CgNode *next;
    struct CgNode *prev;
    CgOwner *f8;
} CgNode; /* size 0xc */

#endif
