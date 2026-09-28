/* Release the ov259 actor's rig while it is live (+0x50 == 1): bit 1 of the +0x60 high byte clears
 * and the +0x214 rig is released (020d1c28). */

#include "nitro/types.h"

struct Hw60 { u16 lo : 8; u16 hi : 8; };

extern void Ov259_Helper_Grab(int rig);

void Ov259_ReleaseRig(char *self)
{
    if (*(int *)(self + 0x50) != 1) {
        return;
    }
    ((struct Hw60 *)(self + 0x60))->hi &= ~2;
    Ov259_Helper_Grab(*(int *)(self + 0x214));
}
