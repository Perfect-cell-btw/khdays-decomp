/* Wander entry of the ov220 enemy. Looks for a target into the
 * actor's +0x390 slot: without one the state ends with sub-state 2. Otherwise the +0x48 side is
 * rolled (0/1) after the +0x44 slot is cleared to -1 and the +0x5c clock zeroed, the +0x18 timer
 * is set to +0x224 + rand(|+0x228 - +0x224| + 1) and the tick hands off to the wander state. */
typedef unsigned char u8;

extern int Ov107_FindNearestObject(int actor, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern int RandNextScaled(int bound);
extern void Ov220_WanderTick(int *node);

void Ov220_BeginWander(int *node)
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
    state[0x11] = -1;
    state[0x17] = 0;
    *(u8 *)(state + 0x16) = RandNextScaled(2);
    lo = *(int *)(*state + 0x224);
    d = *(int *)(*state + 0x228) - lo;
    state[6] = lo + RandNextScaled((d < 0 ? -d : d) + 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov220_WanderTick);
}
