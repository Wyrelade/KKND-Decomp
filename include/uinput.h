#ifndef UINPUT_H
#define UINPUT_H

#include "common.h"

typedef struct UiNode {
    struct UiNode *next;
    struct UiNode *prev;
    s32 field_8;
} UiNode;

typedef struct UiList {
    UiNode *next;
    u8 _pad4[0xC];
    UiNode *field_10;
} UiList;

typedef struct UiEnt {
    u8 _pad0[0x3C];
    UiList *field_3C;
} UiEnt;

typedef struct UiObj {
    u8 _pad0[0x34];
    s32 field_34;
} UiObj;

typedef struct UiNode2 {
    struct UiNode2 *next;
    struct UiNode2 *prev;
    UiObj *field_8;
} UiNode2;

typedef struct UiList2 {
    UiNode2 *next;
    u8 _pad4[0x10];
    s32 field_14;
} UiList2;

#endif
