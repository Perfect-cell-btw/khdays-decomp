/* Queues action 2 and ends the step. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct S {
    AI_TASK_FIELDS(unsigned char *)
};

int Ov220_AiStep_QueueAction2(struct S *r0) {
    (*r0->pState)[0x1c7] = 2;
    return SetIndexedSlot(r0, r0->slot, 0);
}
