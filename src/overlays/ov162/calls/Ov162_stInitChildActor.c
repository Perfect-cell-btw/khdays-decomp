extern void SetSubitemState(void *child, int cmd, int arg, int flag);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov162_RenderAtOwnerScaled(void);
extern void Ov162_TickTimerAdvanceSubState(void);

void Ov162_stInitChildActor(int *node) {
    int *state = (int *)node[1];
    state[1] = *(int *)(*(int *)(*state + 0x3c4) + 0x20);
    *(void **)(state[1] + 0x6c) = Ov162_RenderAtOwnerScaled;
    *(int **)(state[1] + 0x84) = state;
    *(int *)(state[1] + 0x5c) &= ~2;
    state[3] = 6;
    SetSubitemState((void *)state[1], 0, 0, 1);
    SetSubitemState((void *)state[1], 2, 0, 1);
    SetSubitemState((void *)state[1], 4, (short)state[3], 1);
    state[2] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov162_TickTimerAdvanceSubState);
}
