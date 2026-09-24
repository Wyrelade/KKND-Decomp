#ifndef TASKS_H
#define TASKS_H

#include "common.h"

/* Header in front of every block handed out by func_0001A010 (doubly linked). */
typedef struct TaskNode {
    struct TaskNode *field_0;
    struct TaskNode *field_4;
} TaskNode;

typedef struct TaskOwner {
    u8 _pad0[0x8];
    TaskNode *field_8;
} TaskOwner;

#endif
