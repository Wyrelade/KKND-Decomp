#ifndef BUILDING_H
#define BUILDING_H

#include "common.h"

typedef struct BuildingObj {
    u8 _pad0[0x40];
    void (*field_40)();          /* current behaviour routine */
} BuildingObj;

#endif
