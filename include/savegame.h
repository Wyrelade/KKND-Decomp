#ifndef SAVEGAME_H
#define SAVEGAME_H

#include "common.h"

/* Save slot descriptor (0x18 bytes), table D_000D6E84. */
typedef struct SaveSlot {
    s32 field_0;
    u8 _pad4[0x14];
} SaveSlot;

#endif
