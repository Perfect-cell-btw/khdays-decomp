/* Queues action 7 when the animation ends. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Inner {
    unsigned char *p0;
    unsigned char *p4;
};

struct Obj {
    AI_TASK_FIELDS(struct Inner)
};

int Ov272_AiQueue7OnAnimEnd(struct Obj *obj)
{
    struct Inner *inner = obj->pState;

    if (inner->p4[0xad] != 0)
        return (int)obj;

    inner->p0[0x1c7] = 7;
    return SetIndexedSlot(obj, obj->slot, 0);
}
