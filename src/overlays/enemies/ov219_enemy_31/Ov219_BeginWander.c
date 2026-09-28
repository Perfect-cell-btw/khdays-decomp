/* Wander entry of the ov219 enemy (and its byte-identical twin). Looks for a target into the
 * actor's +0x390 slot: without one the state ends with sub-state 2. Otherwise the +0x48 side is
 * rolled (0/1), the +0x44 slot cleared to -1, the +0x1c timer set to +0x224 + rand(|+0x228 -
 * +0x224| + 1) and the tick hands off to the wander state. */

#include "nitro/types.h"

extern int Ov107_FindNearestObject(int actor, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern int RandNextScaled(int bound);
extern void Ov219_WanderTick(int *node);

void Ov219_BeginWander(int *node)
{
    int *state = (int *)node[1];
    int lo;
    int d;

    *(int *)(*state + 0x390) = Ov107_FindNearestObject(*state, 0);
    if (*(int *)(*state + 0x390) == 0) {
        *(u8 *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    *(u8 *)(state + 0x12) = RandNextScaled(2);
    state[0x11] = -1;
    lo = *(int *)(*state + 0x224);
    d = *(int *)(*state + 0x228) - lo;
    state[7] = lo + RandNextScaled((d < 0 ? -d : d) + 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov219_WanderTick);
}
