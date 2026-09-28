/* Ov173_BeginWander: ported from the matched ov166 sibling (same enemy family, constants adjusted). */
extern void Ov107_PostTagUpdate();
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov173_OrbitTick(void);
void Ov173_BeginWander(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 1, 1);
    state[0x18] = (RandNextScaled(2) == 0) ? -1 : 1;
    state[0x13] = RandNextScaled(0x100);
    {
        int lo = *(int *)(*state + 0x224);
        int d = *(int *)(*state + 0x228) - lo;
        if (d < 0) d = -d;
        state[0x17] = lo + RandNextScaled(d + 1);
    }
    state[0x15] = RandNextScaled(0x15) + 0x14;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov173_OrbitTick);
}
