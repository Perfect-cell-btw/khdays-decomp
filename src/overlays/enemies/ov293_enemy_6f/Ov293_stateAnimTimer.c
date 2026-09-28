extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov293_AiWaitNearTargetTick(void);
void Ov293_stateAnimTimer(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 1, 1);
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[5] = v / 5;
    }
    state[0x10] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov293_AiWaitNearTargetTick);
}
