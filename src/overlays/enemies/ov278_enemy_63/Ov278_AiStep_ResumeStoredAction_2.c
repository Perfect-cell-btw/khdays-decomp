/* If active: queues the stored action and ends the step. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Obj {
    AI_TASK_FIELDS(Actor *)
};

void Ov278_AiStep_ResumeStoredAction_2(struct Obj *this) {
    Actor *s = *this->pState;
    if ((unsigned)(s->flags60.raw << 24) >> 24 & 1) {
        s->nextState = s->field_1c9;
        SetIndexedSlot(this, this->slot, 0);
    }
}
