/* AI step: when the byte behind context +0x48 is clear, pendingAction (+0x1c7) = 2 and the step
 * handler is cleared. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Sub {
    unsigned char *p00;
    char pad[0x44];
    unsigned char *p48;
};

struct Obj {
    AI_TASK_FIELDS(struct Sub)
};

void Ov120_AiStep_QueueAction2OnFlag48Clear(struct Obj *o)
{
    struct Sub *s = o->pState;

    if (s->p48[0] != 0)
        return;

    s->p00[0x1c7] = 2;
    SetIndexedSlot(o, o->slot, 0);
}
