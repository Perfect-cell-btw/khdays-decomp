extern void Ov107_PostTagUpdate();
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov152_TriggerWhenTargetInRange(void);
void Ov152_stateTimerRandomRange(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 5;
    }
    Ov107_PostTagUpdate(*state, 1, 1);
    {
        int lo = *(int *)(*state + 0x224);
        int diff = *(int *)(*state + 0x228) - lo;
        if (diff < 0) diff = -diff;
        state[0xd] = lo + RandNextScaled(diff + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov152_TriggerWhenTargetInRange);
}
