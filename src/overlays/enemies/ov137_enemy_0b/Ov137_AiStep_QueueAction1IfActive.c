/* AI step: once the actor is active (bit 0 of its flags at +0x60), sets its pending action (+0x1c7)
 * and clears the step handler. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct Obj {
    char _pad0[4];
    Actor **pp;                 /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov137_AiStep_QueueAction1IfActive(struct Obj *this) {
    Actor *s = *this->pp;
    if (s->flags60.bits.lo & 1) {
        s->nextState = 1;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
