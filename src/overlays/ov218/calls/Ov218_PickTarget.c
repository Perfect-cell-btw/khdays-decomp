/* Target pick of the ov218 actor: the nearest target (020cab14) goes to +0x390; without one the next
 * move is 2 and the node ends. Otherwise +0x48 is -1, +0x60 clears, a random side (+0x5c) is drawn,
 * the +0x18 wait is rolled between +0x224 and +0x228 and the node moves on to 020ccfa8. */
extern int Ov107_FindNearestObject(int actor, int *distOut);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov218_CircleTick(void);

void Ov218_PickTarget(int *node)
{
    int *state = (int *)node[1];
    int lo;
    int span;

    *(int *)(*state + 0x390) = Ov107_FindNearestObject(*state, 0);
    if (*(int *)(*state + 0x390) == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    state[0x12] = -1;
    state[0x18] = 0;
    *((unsigned char *)state + 0x5c) = RandNextScaled(2);
    lo = *(int *)(*state + 0x224);
    span = *(int *)(*state + 0x228) - lo;
    if (span < 0) {
        span = -span;
    }
    state[6] = lo + RandNextScaled(span + 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov218_CircleTick);
}
