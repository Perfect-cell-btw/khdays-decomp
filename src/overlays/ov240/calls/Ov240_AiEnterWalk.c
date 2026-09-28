extern void Ov107_PostTagUpdate();
extern void Ov240_startAnim();
extern int RandNextScaled(int);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov240_WanderTick(void);

void Ov240_AiEnterWalk(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 2, 1);
    Ov240_startAnim(*state, 0);
    {
        int lo = *(int *)(*state + 0x224);
        int hi = *(int *)(*state + 0x228);
        int d = hi - lo;
        if (d < 0) d = -d;
        state[0xe] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov240_WanderTick);
}
