/* AI step: once the actor is active (bit 0 of its flags at +0x60), makes its stored action (+0x1c9)
 * the pending action (+0x1c7) and clears the step handler. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Obj {
    AI_TASK_FIELDS(Actor *)
};

void Ov147_AiStep_QueueStoredActionIfActive(struct Obj *this) {
    Actor *s = *this->pState;
    if ((unsigned)(s->flags60.raw << 24) >> 24 & 1) {
        s->nextState = s->field_1c9;
        SetIndexedSlot(this, this->slot, 0);
    }
}
