#include "nitro/types.h"
#include "game/ai_task.h"

/* Runs one update of a task list (an actor's AI tasks, see game/ai_task.h): each task's pending
 * start callback, then its three step callbacks pass by pass, then tears down the tasks that asked
 * to stop. The list is walked by List_First / List_Next, which return the task stored in each
 * node. */

typedef struct Owner {
    u8 pad_00[0x28];
    int updateCount; /* 0x28 */
    int scaledTime;  /* 0x2c */
} Owner;

extern AiTask *List_First(Owner *owner);
extern AiTask *List_Next(Owner *owner);
extern void DestroyListNode(Owner *owner, AiTask *item);

void ObjList_Update(Owner *owner, int tick)
{
    AiTask *item;
    s8 pendingSlot;
    int slot;

    owner->scaledTime = (int)(((long long)tick * 0x88 + 0x800) >> 12);

    pendingSlot = 1;
    item = List_First(owner);
    while (item != 0) {
        if (item->pfnStart != 0) {
            item->slot = pendingSlot;
            item->pfnStart(item);
            item->pfnStart = 0;
        }
        item = List_Next(owner);
    }

    for (slot = 0; slot < 3; slot++) {
        item = List_First(owner);
        while (item != 0) {
            if (item->stop == 0 && item->pfnStep[slot] != 0) {
                item->slot = (s8)slot;
                item->pfnStep[slot](item);
            }
            item = List_Next(owner);
        }
    }

    /*
     * Tearing an item down re-links the list, so the walk restarts from the
     * head after every removal and only advances when nothing was removed.
     * The shared re-check block is what the original emits; an if/else loop
     * duplicates the "next" call and compiles 8 bytes long.
     */
restart:
    item = List_First(owner);
    if (item == 0) {
        goto done;
    }
check:
    if (item->stop != 0) {
        DestroyListNode(owner, item);
        goto restart;
    }
    item = List_Next(owner);
    if (item != 0) {
        goto check;
    }
done:
    owner->updateCount++;
}
