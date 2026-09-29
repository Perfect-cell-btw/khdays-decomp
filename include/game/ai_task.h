#ifndef GAME_AI_TASK_H
#define GAME_AI_TASK_H

/* An actor's AI task: an entry of the task list the actor keeps at +0x03c. CreateRegistryEntry
 * inserts the 0x28-byte entry into the list, allocates the task's zeroed state block (its size is
 * the caller's) and records the start and teardown callbacks and a fresh id. ObjList_Update then
 * runs, every update, the start callback once (with `slot` 1) and the three step callbacks, one per
 * pass, each with `slot` set to its pass; SetIndexedSlot changes a step callback, usually the one
 * of the pass that is running (`slot`).
 *
 * The state block belongs to whoever created the task, so each enemy declares its tasks with its
 * own state type: `struct MyTask { AI_TASK_FIELDS(MyState) };` gives `pState` that type. */

#include "nitro/types.h"

#define AI_TASK_FIELDS(StateType)                                                          \
    void *pList;                    /* 0x00: the task list it is in */                      \
    StateType *pState;              /* 0x04: its state block */                             \
    void (*pfnStep[3])();           /* 0x08: run every update, one per pass */              \
    void (*pfnStart)();             /* 0x14: run once at the next update, then cleared */   \
    void (*pfnTeardown)();          /* 0x18 */                                              \
    int id;                         /* 0x1c */                                              \
    s8 slot;                        /* 0x20: the pass running now (1 while starting) */     \
    u8 pad21[3];                                                                            \
    int stop;                       /* 0x24: nonzero: tear the task down */

typedef struct AiTask {
    AI_TASK_FIELDS(void)
} AiTask;

#endif /* GAME_AI_TASK_H */
