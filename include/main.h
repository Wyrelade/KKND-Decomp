#ifndef MAIN_H
#define MAIN_H

#include "common.h"

/* Map/view extent block reached through D_000B98D8->field_8. */
typedef struct MainView {
    u8 _pad0[0x24];
    s32 field_24;
    s32 field_28;
} MainView;

typedef struct MainGlobal {
    u8 _pad0[0x8];
    MainView *field_8;
} MainGlobal;

/* Rectangle-ish record filled by func_00010EE0. */
typedef struct MainRect {
    u8 _pad0[0x24];
    s32 field_24;
    s32 field_28;
    s32 field_2C;
} MainRect;

#endif
