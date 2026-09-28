extern void SetSubitemState(void *p, int a, int b, int c);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov202_RenderAtOwnerModel(void);
extern void Ov202_ConfigureActorUnlessBusy(void);

void Ov202_stateInitSubitem(char *obj) {
    int *state = *(int **)(obj + 4);
    int *sub = *(int **)(*(int *)(*state + 0x3dc));
    state[1] = (int)sub;
    *(void **)((char *)sub + 0x6c) = Ov202_RenderAtOwnerModel;
    *(int **)(state[1] + 0x84) = state;
    *(int *)(state[1] + 0x5c) &= ~2;
    SetSubitemState((void *)state[1], 2, 0, 0);
    SetSubitemState((void *)state[1], 0, 0, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov202_ConfigureActorUnlessBusy);
}
