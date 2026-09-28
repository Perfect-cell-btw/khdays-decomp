/* Reach check tick of the ov160 enemy: the target is re-acquired into +8 with its squared
 * distance; with one, the gap is that distance's root less both +0x80 radii (else the gap is
 * "infinite"). While the +0x44 delay is positive and the gap is at least half the owner's
 * +0x2d8 reach nothing happens; otherwise sub-state 4 is queued and the state ends. */
extern int Ov107_FindNearestObject(int owner, int *outDist);
extern int FX_Sqrt(int x);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov160_ReachCheckTick(int *node)
{
    int *state = (int *)node[1];
    int gap;
    int owner;
    int target;

    target = state[2] = Ov107_FindNearestObject(*state, &gap);
    if (target == 0) {
        gap = 0x7fffffff;
    } else {
        owner = *state;
        gap = FX_Sqrt(gap) - *(int *)(target + 0x80) - *(int *)(owner + 0x80);
    }
    if (state[0x11] > 0 && gap >= *(int *)(*state + 0x2d8) / 2) {
        return;
    }
    *(unsigned char *)(*state + 0x1c7) = 4;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
