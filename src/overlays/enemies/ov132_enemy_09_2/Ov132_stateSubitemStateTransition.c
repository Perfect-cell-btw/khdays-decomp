extern void SetSubitemState();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov132_FinishIfSubFlagClear(void);
void Ov132_stateSubitemStateTransition(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x310) == 0xa) return;
    SetSubitemState(state[1], 2, 1, 0);
    SetSubitemState(state[1], 0, 2, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov132_FinishIfSubFlagClear);
}
