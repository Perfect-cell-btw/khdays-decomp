/* Queues action 2 once the watched flag clears. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Inner {
    unsigned char *ptr0;        /* +0x00 */
    char pad[0x30 - 4];
    unsigned char *flagptr;     /* +0x30 */
};

struct Obj {
    AI_TASK_FIELDS(struct Inner)
};

void Ov123_AiQueue2OnFlagClear(struct Obj *obj)
{
    struct Inner *inner = obj->pState;
    if (inner->flagptr[0] != 0) {
        return;
    }
    inner->ptr0[0x1c7] = 2;
    SetIndexedSlot(obj, obj->slot, 0);
}
