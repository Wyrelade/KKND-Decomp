#ifndef GFX_H
#define GFX_H

#include "common.h"

/* Driver method table: slot 0 is the control entry point. */
typedef struct GfxVtbl {
    int (*field_0)(void *self, int op);
} GfxVtbl;

typedef struct GfxDriver {
    u8 _pad0[0x4];
    GfxVtbl *field_4;
} GfxDriver;

#endif
