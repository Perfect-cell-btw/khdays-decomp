extern void Ov107_PostTagUpdate();
extern void Ov216_loadDefaultPoseVecs();
extern int RandNextScaled(int);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov216_SteerTowardTarget(void);

void Ov216_stEnterRandDelay(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 2, 1);
    Ov216_loadDefaultPoseVecs(*state, 0);
    {
        int lo = *(int *)(*state + 0x224);
        int hi = *(int *)(*state + 0x228);
        int d = hi - lo;
        if (d < 0) d = -d;
        state[0x14] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov216_SteerTowardTarget);
}
