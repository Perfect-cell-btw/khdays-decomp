/* Re-arm the five hit slots (0, 2, 4, 1, 3) of the +0x38c collision handle with the actor's
 * +0x310 kind byte and its +0x311 bit-0 flag. */

#include "game/actor.h"
#include "game/engine.h"

struct S {
    Actor base;                  /* 0x000 */
    void *p38c;
};

void Ov273_RearmHitSlots(struct S *s) {
    SetSubitemState(s->p38c, 0, s->base.mode310, s->base.flags311.bits.bit0);
    SetSubitemState(s->p38c, 2, s->base.mode310, s->base.flags311.bits.bit0);
    SetSubitemState(s->p38c, 4, s->base.mode310, s->base.flags311.bits.bit0);
    SetSubitemState(s->p38c, 1, s->base.mode310, s->base.flags311.bits.bit0);
    SetSubitemState(s->p38c, 3, s->base.mode310, s->base.flags311.bits.bit0);
}
