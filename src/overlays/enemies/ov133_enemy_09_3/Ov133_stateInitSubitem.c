/* State step: binds the child subitem (+0x3c4) to this state (render callback and back pointer),
 * clears its flag bit 1, rewinds its animation tracks 0 and 2 and installs the next step. */

extern void SetSubitemState();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov133_RenderAtOwnerModel(void);
extern void Ov133_ConfigureActorUnlessBusy(void);
void Ov133_stateInitSubitem(int *node) {
    int *state = (int *)node[1];
    int sub = *(int *)(*(int *)(*state + 0x3c4));
    state[1] = sub;
    *(void **)(sub + 0x6c) = Ov133_RenderAtOwnerModel;
    *(int **)(state[1] + 0x84) = state;
    *(unsigned int *)(state[1] + 0x5c) &= 0xfffffffd;
    SetSubitemState(state[1], 2, 0, 0);
    SetSubitemState(state[1], 0, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov133_ConfigureActorUnlessBusy);
}
