#ifndef NETIPX_H
#define NETIPX_H

#include "common.h"

typedef struct NetIpxPacket {
    u8 _pad0[0x2F];
    s32 field_2F;                /* unaligned: structures are packed (-zp1) */
} NetIpxPacket;

typedef struct IpxTag {
    u8 _pad0[0xC];
    s32 field_C;
} IpxTag;

typedef struct IpxStat {
    u8 _pad0[0x10];
    s32 field_10;
    u8 _pad14[0x28];
    s32 field_3C;
    s32 field_40;
} IpxStat;

typedef struct IpxBldg {
    u8 _pad0[0xC];
    IpxTag *field_C;
    u8 _pad10[4];
    s32 field_14;
    IpxStat *field_18;
    u8 _pad1C[0x24];
    void (*field_40)();
    u8 _pad44[0x18];
    s32 field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0x10];
    s32 field_94;
    u8 _pad98[0x98];
    s32 field_130;
} IpxBldg;

#endif
