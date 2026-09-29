/* SetSubitemState on model track 0 with the actor's stored animation (+0x310) and flag, then
 * RefreshObjectCallbacks. */

#include "game/actor.h"
#include "game/engine.h"

void Ov219_Model_ReapplyTrack0(Actor *this) {
    SetSubitemState(this->pSubitem, 0, this->mode310, this->flags311.bits.bit0);
    RefreshObjectCallbacks(this->pSubitem, 0);
}
