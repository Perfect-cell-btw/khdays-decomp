/* Sets the local player's lock bits and arms the state. */

#include "game/engine.h"

extern int Ov022_ActorSetState();

int Ov032_ArmPlayerLock(int *r0)
{
    int *r4 = r0;

    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)r4 + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)r4 + 0x46c) |= 0x10000;
    }
    return Ov022_ActorSetState(r4, 0x22);
}
