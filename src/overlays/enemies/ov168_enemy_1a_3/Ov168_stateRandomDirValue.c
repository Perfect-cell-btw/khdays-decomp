/* State step: posts a tag update, then picks a random direction sign and a random radius between
 * the actor's limits at +0x224 and +0x228; installs the circling step. */

extern void Ov107_PostTagUpdate();
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov168_CircleTick(void);
void Ov168_stateRandomDirValue(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 1, 1);
    state[0x18] = (RandNextScaled(2) == 0) ? -1 : 1;
    {
        int lo = *(int *)(*state + 0x224);
        int d = *(int *)(*state + 0x228) - lo;
        if (d < 0) d = -d;
        state[0x17] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov168_CircleTick);
}
