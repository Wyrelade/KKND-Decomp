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
    struct IniHook *field_4;
    s32 field_8;                 /* id */
    int (*field_C)(void);
    void (*field_10)(void);
    void (*field_14)(void);
} IniHook;

/* Static hook definition (table D_000C4EE8, terminated by id 0). */
typedef struct IniHookDef {
    s32 id;
    int (*field_4)(void);
    void (*field_8)(void);
    void (*field_C)(void);
} IniHookDef;

#endif
