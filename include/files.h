#ifndef FILES_H
#define FILES_H

#include "common.h"

/* 8-byte chunk header in front of a data block; size is stored big-endian. */
typedef struct FileHdr {
    s32 field_0;
    u32 size;
} FileHdr;

#define FILES_BSWAP32(x) ((((x) & 0xff) << 24) | (((x) & 0xff00) << 8) \
    | (((x) & 0xff0000) >> 8) | (((x) & 0xff000000) >> 24))

/* Task signalled when a background load completes (flag bit in field_20, mirrored into 0x24). */
typedef struct FileTask {
    u8 _pad0[0x20];
    u32 field_20;
    u32 field_24;
} FileTask;

/* Background load request (0x14 bytes, func_00068BB0). state: 1 loading, 2 done, 0 failed. */
typedef struct FileLoad {
    s32 state;
    int fh;
    u8 *buf;
    u32 size;
    FileTask *owner;
} FileLoad;

/* Loader task created by func_0001A270; its request sits at 0x3C. */
typedef struct FileJob {
    u8 _pad0[0x3C];
    FileLoad *field_3C;
} FileJob;

#endif
