/* Queues action 1 once the item is active. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct Obj {
    char _pad0[4];
    Actor **pp;                 /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov231_Item_AiWaitActive(struct Obj *this) {
    Actor *s = *this->pp;
    if (s->flags60.bits.lo & 1) {
        s->nextState = 1;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
