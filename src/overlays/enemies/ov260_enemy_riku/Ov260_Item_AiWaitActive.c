/* Queues action 1 once the item is active. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Obj {
    AI_TASK_FIELDS(Actor *)
};

void Ov260_Item_AiWaitActive(struct Obj *this) {
    Actor *s = *this->pState;
    if (s->flags60.bits.lo & 1) {
        s->nextState = 1;
        SetIndexedSlot(this, this->slot, 0);
    }
}
