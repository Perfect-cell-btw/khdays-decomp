/* Sets bits 0-1 of the actor's first flag word and ends the step. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Sub {
    char pad0x1ae[0x1ae];
    unsigned short flags;
};

struct Obj {
    AI_TASK_FIELDS(struct Sub *)
};

int Ov237_AiStep_SetFlags3AndEnd(struct Obj *r0)
{
    (*r0->pState)->flags |= 3;
    return SetIndexedSlot(r0, r0->slot, 0);
}
