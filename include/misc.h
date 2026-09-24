#ifndef MISC_H
#define MISC_H

#include "common.h"

/* Object pair handled by func_000122A0: only the handle at 0x6C is used. */
typedef struct MiscObj {
    u8 _pad0[0x6C];
    s32 field_6C;
} MiscObj;

#endif
