/* Sets model track 0 to the variant animation and refreshes callbacks. */

#include "game/actor.h"

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

void Ov245_FourShape_ApplyAnim(Actor *this) {
    SetSubitemState(this->pSubitem, 0, this->mode310, this->flags311.bits.bit0);
    RefreshObjectCallbacks(this->pSubitem, 0);
}
