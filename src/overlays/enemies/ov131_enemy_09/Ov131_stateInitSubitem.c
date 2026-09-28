/* State step: binds the child subitem (+0x3c4) to this state (render callback and back pointer),
 * clears its flag bit 1, rewinds its animation tracks 2 and 0 and installs the next step. */

extern void SetSubitemState(void *p, int a, int b, int c);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov131_RenderAtOwnerModel(void);
extern void Ov131_ConfigureActorUnlessBusy(void);

void Ov131_stateInitSubitem(char *obj) {
    int *state = *(int **)(obj + 4);
    int *sub = *(int **)(*(int *)(*state + 0x3c4));
    state[1] = (int)sub;
    *(void **)((char *)sub + 0x6c) = Ov131_RenderAtOwnerModel;
    *(int **)(state[1] + 0x84) = state;
    *(int *)(state[1] + 0x5c) &= ~2;
    SetSubitemState((void *)state[1], 2, 0, 0);
    SetSubitemState((void *)state[1], 0, 0, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov131_ConfigureActorUnlessBusy);
}
