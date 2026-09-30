/* AI step: when the byte behind context +0x48 is clear, pendingAction (+0x1c7) = 9 and the step
 * handler is cleared. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Obj {
    AI_TASK_FIELDS(struct Sub)
};

struct Sub {
    char *s0;
    char pad[0x48 - 4];
    unsigned char *p48;
};

int Ov162_AiStep_QueueAction9OnFlag48Clear(struct Obj *a) {
    struct Sub *s = a->pState;
    if (s->p48[0] != 0)
        return (int)a;
    s->s0[0x1c7] = 9;
    return SetIndexedSlot(a, a->slot, 0);
}
