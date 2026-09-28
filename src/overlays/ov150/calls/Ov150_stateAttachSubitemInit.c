extern void SetSubitemState(int obj, int idx, int a, int b);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov150_RenderPerSphere(void);
extern void Ov150_FinishIfSubFlagClear(void);
void Ov150_stateAttachSubitemInit(int *node) {
    void *cb = (void *)Ov150_RenderPerSphere;
    int *state = (int *)node[1];
    int sub = *(int *)(*(int *)(*state + 0x390));
    state[1] = sub;
    *(void **)(state[1] + 0x6c) = cb;
    *(int **)(state[1] + 0x84) = state;
    SetSubitemState(state[1], 0, 0, 0);
    SetSubitemState(state[1], 4, 0, 0);
    SetSubitemState(state[1], 1, 0, 0);
    SetSubitemState(state[1], 2, 0, 0);
    *(unsigned int *)(state[1] + 0x5c) &= ~2;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov150_FinishIfSubFlagClear);
}
