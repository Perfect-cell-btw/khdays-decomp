/* Queues action 9 once the watched flag clears. */

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

int Ov185_AiQueue9OnFlagClear(struct Obj *a) {
    struct Sub *s = a->pState;
    if (s->p48[0] != 0)
        return (int)a;
    s->s0[0x1c7] = 9;
    return SetIndexedSlot(a, a->slot, 0);
}
