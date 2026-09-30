/* Queues action 2 once the watched slot (+0x44) is empty. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Inner {
    unsigned char *ptr0;
    char pad4[0x40];
    unsigned char *ptr44;
};

struct Obj {
    AI_TASK_FIELDS(struct Inner)
};

void Ov141_AiStep_QueueAction2WhenFree(struct Obj *obj) {
    struct Inner *inner = obj->pState;
    if (inner->ptr44[0] != 0) {
        return;
    }
    inner->ptr0[0x1c7] = 2;
    SetIndexedSlot(obj, obj->slot, 0);
}
