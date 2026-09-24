#ifndef MOB_H
#define MOB_H

#include "common.h"

/* Mob (animated object) node: doubly linked list, script pointers at 0x4C/0x50. */
typedef struct Mob {
    struct Mob *field_0;
    struct Mob *field_4;
    u8 _pad8[0x4];
    s32 field_C;
    u8 _pad10[0x3C];
    s32 *field_4C;
    s32 *field_50;
    s32 field_54;
    s32 field_58;
    u8 _pad5C[0x4];
    s32 field_60;
    s32 field_64;
    u8 _pad68[0x4];
    void *field_6C;
} Mob;

#endif
