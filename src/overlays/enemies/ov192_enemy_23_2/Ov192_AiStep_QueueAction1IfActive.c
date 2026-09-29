/* AI step: once the actor is active (bit 0 of its flags at +0x60), sets its pending action (+0x1c7)
 * and clears the step handler. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Obj {
    AI_TASK_FIELDS(Actor *)
};

void Ov192_AiStep_QueueAction1IfActive(struct Obj *this) {
    Actor *s = *this->pState;
    if (s->flags60.bits.lo & 1) {
        s->nextState = 1;
        SetIndexedSlot(this, this->slot, 0);
    }
}
