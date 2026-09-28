/* If active: queues the stored action and ends the step. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct Obj {
    char _pad0[4];
    Actor **pp;                 /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov273_AiStep_ResumeStoredAction_2(struct Obj *this) {
    Actor *s = *this->pp;
    if ((unsigned)(s->flags60.raw << 24) >> 24 & 1) {
        s->nextState = s->field_1c9;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
