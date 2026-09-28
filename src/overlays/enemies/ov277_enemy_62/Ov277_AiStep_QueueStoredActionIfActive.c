/* AI step: once the actor is active (bit 0 of its flags at +0x60), makes its stored action (+0x1c9)
 * the pending action (+0x1c7) and clears the step handler. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct Obj {
    char _pad0[4];
    Actor **pp;                 /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov277_AiStep_QueueStoredActionIfActive(struct Obj *this) {
    Actor *s = *this->pp;
    if ((unsigned)(s->flags60.raw << 24) >> 24 & 1) {
        s->nextState = s->field_1c9;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
