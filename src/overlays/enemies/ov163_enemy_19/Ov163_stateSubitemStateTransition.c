/* State step: unless the actor's animation state (+0x310) is 0xa, starts the subitem's tracks 2 and
 * 0 on their next animations and installs the finishing step. */

extern void SetSubitemState();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov163_FinishIfSubFlagClear(void);
void Ov163_stateSubitemStateTransition(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x310) == 0xa) return;
    SetSubitemState(state[1], 2, 1, 0);
    SetSubitemState(state[1], 0, 2, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov163_FinishIfSubFlagClear);
}
