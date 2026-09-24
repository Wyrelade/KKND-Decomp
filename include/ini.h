#ifndef INI_H
#define INI_H

#include "common.h"

/* One line of a loaded .ini text (singly linked list). */
typedef struct IniLine {
    char *field_0;
    s32 field_4;
    struct IniLine *field_8;
} IniLine;

/* Registered ini/module hook (circular list headed by D_000D6E18). */
typedef struct IniHook {
    struct IniHook *field_0;
    u8 _pad4[0x8];
    int (*field_C)(void);
    u8 _pad10[0x4];
    void (*field_14)(void);
} IniHook;

#endif
