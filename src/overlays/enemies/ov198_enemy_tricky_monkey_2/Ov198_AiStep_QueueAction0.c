/* Queues action 0 and ends the step. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct A {
    AI_TASK_FIELDS(char *)
};

int Ov198_AiStep_QueueAction0(struct A *a) {
    (*a->pState)[0x1c7] = 0;
    return SetIndexedSlot(a, a->slot, 0);
}
