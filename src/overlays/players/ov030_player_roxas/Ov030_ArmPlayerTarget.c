/* Sets the local player's lock bits, stores the target and arms the tracking state. */

#include "game/engine.h"

extern int Ov022_ActorSetState();

int Ov030_ArmPlayerTarget(int *r0, int r1)
{
    int *r6 = r0;
    int r5 = r1;
    int *r4 = (int *)r6[0xdb4 / 4];

    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)r4 + 0x464) |= 0x10000;
    }
    *(long long *)((char *)r4 + 0x46c) |= 0x10000;
    r6[1] = 0;
    r6[0] = r5;
    if (r5 != 0) {
        return Ov022_ActorSetState(r4, 0x23);
    }
    return Ov022_ActorSetState(r4, 0x22);
}
