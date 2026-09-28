/* State step: posts a tag update, then randomises the movement: a direction sign, a starting phase,
 * a radius between the actor's limits at +0x224 and +0x228 and a timer; installs the orbit step. */

extern void Ov107_PostTagUpdate();
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov172_OrbitTick(void);
void Ov172_stateRandomInitFull(int *node) {
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
    state[0x15] = RandNextScaled(1) + 0x78;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov172_OrbitTick);
}
