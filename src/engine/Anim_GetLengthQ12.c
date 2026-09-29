/* Returns the length of an animation channel's animation in fx32 frames, or 0 when the channel is
 * unbound. */

#include "game/engine.h"

int Anim_GetLengthQ12(char *pR0, int r1) {
    unsigned short *r0 = (unsigned short *)pR0;
    unsigned short **p;
    p = Anim_GetChannelState(r0, r1);
    if (!p) {
        return 0;
    }
    return p[2][2] << 12;
}
