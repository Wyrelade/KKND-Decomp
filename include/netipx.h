#ifndef NETIPX_H
#define NETIPX_H

#include "common.h"

typedef struct NetIpxPacket {
    u8 _pad0[0x2F];
    s32 field_2F;                /* unaligned: structures are packed (-zp1) */
} NetIpxPacket;

#endif
