extern void SetSubitemState();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov162_RenderAtOwnerModel(void);
extern void Ov162_ConfigureActorUnlessBusy(void);
void Ov162_stateInitSubitem(int *node) {
    int *state = (int *)node[1];
    int sub = *(int *)(*(int *)(*state + 0x3c4));
    state[1] = sub;
    *(void **)(sub + 0x6c) = Ov162_RenderAtOwnerModel;
    *(int **)(state[1] + 0x84) = state;
    *(unsigned int *)(state[1] + 0x5c) &= 0xfffffffd;
    SetSubitemState(state[1], 2, 0, 0);
    SetSubitemState(state[1], 0, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov162_ConfigureActorUnlessBusy);
}
