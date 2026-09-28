extern void SetSubitemState(void *child, int cmd, int arg, int flag);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov163_RenderAtOwnerScaled(void);
extern void Ov163_TickTimerAdvanceSubState(void);

void Ov163_stInitChildActor(int *node) {
    int *state = (int *)node[1];
    state[1] = *(int *)(*(int *)(*state + 0x3c4) + 0x18);
    *(void **)(state[1] + 0x6c) = Ov163_RenderAtOwnerScaled;
    *(int **)(state[1] + 0x84) = state;
    *(int *)(state[1] + 0x5c) &= ~2;
    state[3] = 6;
    SetSubitemState((void *)state[1], 0, 0, 1);
    SetSubitemState((void *)state[1], 2, 0, 1);
    SetSubitemState((void *)state[1], 4, (short)state[3], 1);
    state[2] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov163_TickTimerAdvanceSubState);
}
