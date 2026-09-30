/* Sets model tracks 0, 2, 4 and 1 to the variant animation and refreshes callbacks. */

#include "game/actor.h"

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

int Ov254_HelperE_ApplyAnims(Actor *s) {
    SetSubitemState(s->pSubitem, 0, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 2, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 4, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 1, s->mode310, s->flags311.bits.bit0);
    return RefreshObjectCallbacks(s->pSubitem, 0);
}
