#ifndef UNCOVER_H
#define UNCOVER_H

#include "common.h"

typedef struct UncEnt {
    u8 _pad0[0x40];
    void (*f40)(struct UncEnt *);
} UncEnt;

typedef struct UncDef {
    u8 _pad0[0x4c];
    s32 f4c;                     /* 0x1000 = uses the uncover path */
} UncDef;

typedef struct UncFlags {
    u8 _pad0[0xb];
    u8 fb;
    u8 _padc[0xc];
    s32 f18;
} UncFlags;

typedef struct UncPos {
    u8 _pad0[0x10];
    s32 f10;                     /* x */
    s32 f14;                     /* y */
    u8 _pad18[0x4];
    s32 f1c;
    s32 f20;
    u8 _pad24[0x34];
    void *f58;
    u8 _pad5c[0xc];
    struct UncFlags *f68;
    u8 _pad6c[0x1c];
    s32 f88;
} UncPos;

typedef struct UncUnit {
    u8 _pad0[0x18];
    UncDef *f18;
    u8 _pad1c[0x40];
    UncPos *f5c;
    u8 _pad60[0x48];
    s32 fa8;
    s32 fac;
    s32 fb0;
} UncUnit;

/* List node; D_000D1320 is the sentinel head (func_000520E0). */
typedef struct UncNode {
    struct UncNode *next;
    s32 f4;
    s32 f8;                      /* key */
    s32 fc;                      /* value */
} UncNode;

typedef struct UncGridItem {
    u8 _pad0[0x18];
    s32 f18;
} UncGridItem;
typedef struct UncGridNode {
    struct UncGridNode *next;
    UncGridItem *f4;
} UncGridNode;
typedef struct UncTileSet {
    u8 _pad0[0xc];
    s32 fc;
} UncTileSet;
typedef struct UncGridOwner {
    u8 _pad0[0x84];
    UncTileSet *f84;
} UncGridOwner;
typedef struct UncGrid {
    u8 _pad0[8];
    UncGridNode *f8;
    s32 fc;
    s32 f10;
    UncGridOwner *f14;
} UncGrid;

typedef struct UncTgt {
    u8 _pad0[0x6c];
    s32 f6c;
} UncTgt;

typedef struct UncCtl {
    u8 _pad0[8];
    UncFlags *f8;
} UncCtl;

#endif
