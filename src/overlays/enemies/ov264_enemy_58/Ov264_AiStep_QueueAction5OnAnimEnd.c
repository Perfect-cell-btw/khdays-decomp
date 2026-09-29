/* Queues action 5 when the animation ends. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct s1 {
    char *p0;
    char *p1;
};

struct s0 {
    AI_TASK_FIELDS(struct s1)
};

void Ov264_AiStep_QueueAction5OnAnimEnd(struct s0 *a) {
    struct s1 *r2 = a->pState;
    if (*(unsigned char *)(r2->p1 + 0xad) != 0) {
        return;
    }
    *(unsigned char *)(r2->p0 + 0x1c7) = 5;
    SetIndexedSlot(a, a->slot, 0);
}
