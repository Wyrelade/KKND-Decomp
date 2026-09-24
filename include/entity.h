#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"

/*
 * Game object with a state/controller block at +0x3C. The state's +0x10 is a handler
 * called as state->handler(state) (func_0001EC70) and swapped by message handlers
 * (func_0001EB90 installs func_0001EBB0 on message 0x5DC).
 */
typedef struct EntityState {
    u8 _pad0[0xC];
    s32 field_C;                 /* set to 1 by outpost message 0x609 (func_0003B6A0) */
    void (*handler)(struct EntityState *);
} EntityState;

typedef struct Entity {
    u8 _pad0[0x3C];
    EntityState *state;
} Entity;

#endif
