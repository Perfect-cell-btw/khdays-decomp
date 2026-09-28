/* SetSubitemState on model tracks 0, 2, 4 and 1 with the actor's stored animation (+0x310), then
 * RefreshObjectCallbacks. */

#include "game/actor.h"

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

int Ov208_Model_ReapplyTracks(Actor *s) {
    SetSubitemState(s->pSubitem, 0, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 2, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 4, s->mode310, s->flags311.bits.bit0);
    SetSubitemState(s->pSubitem, 1, s->mode310, s->flags311.bits.bit0);
    return RefreshObjectCallbacks(s->pSubitem, 0);
}
