#ifndef MESSAGE_H
#define MESSAGE_H

#include "common.h"

typedef struct MsgNode {
    struct MsgNode *next;
} MsgNode;

typedef struct MsgPool {
    u8 _pad0[0x30];
    MsgNode *field_30;
} MsgPool;

#endif
