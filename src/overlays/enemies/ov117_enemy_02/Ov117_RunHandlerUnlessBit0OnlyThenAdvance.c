/* Post-tick: unlinks the held node when the actor is inactive or flagged, then runs the base
 * post-tick. */

#include "game/enemy_common.h"

extern void Ov117_UnlinkHeldNode();

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov117_RunHandlerUnlessBit0OnlyThenAdvance(int this_) {
    unsigned int lo = ((struct hw60 *)(this_ + 0x60))->lo;
    if ((lo & 0x80) || !(lo & 1)) {
        Ov117_UnlinkHeldNode(this_);
    }
    Ov107_AiState_PostTickBase((char *)this_);
}
