#ifndef ENEMYAI_H
#define ENEMYAI_H

#include "common.h"

typedef struct AiEnt {
    u8 _pad0[0x40];
    void (*f40)();               /* current behaviour routine */
} AiEnt;

typedef struct AiB { u8 _pad0[0xc]; s32 fc; } AiB;
typedef struct AiNode { struct AiNode *next; u8 _pad4[8]; AiB *fc; } AiNode;

typedef struct AiGroup {
    u8 _pad0[0xc];
    AiNode fc;                   /* member list sentinel */
    u8 _pad1c[8];
    s32 f24;
    u8 _pad28[0x14];
    s32 f3c;                     /* target x */
    s32 f40;                     /* target y */
} AiGroup;

typedef struct AiPlayer { u8 _pad0[0x2a0]; s32 f2a0; } AiPlayer;
typedef struct AiMsg { s32 f0; s32 f4; s32 f8; } AiMsg;

#endif
