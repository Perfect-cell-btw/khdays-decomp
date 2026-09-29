/* Queues action 0 when the animation ends. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Inner {
    char *p0;
    char *p1;
};

struct Obj {
    AI_TASK_FIELDS(struct Inner)
};

void Ov254_AiStep_QueueAction0OnAnimEnd_3(struct Obj *obj) {
    struct Inner *inner = obj->pState;
    if (*(unsigned char *)(inner->p1 + 0xad) != 0) {
        return;
    }
    *(char *)(inner->p0 + 0x1c7) = 0;
    SetIndexedSlot(obj, obj->slot, 0);
}
