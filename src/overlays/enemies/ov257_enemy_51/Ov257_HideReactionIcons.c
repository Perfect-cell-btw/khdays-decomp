/* Hide the two reaction icons (slots 2 and 0, state 2) and register the recover callback, unless
 * the animation is still on the hit frame (*node+0x1c6 == 9). */
extern void SetSubitemState(int obj, int slot, int a, int b);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov257_FinishIfSubFlagClear(void);

void Ov257_HideReactionIcons(int param_1) {
    int *node = *(int **)(param_1 + 4);
    if (*(signed char *)(*node + 0x1c6) == 9) {
        return;
    }
    SetSubitemState(node[1], 2, 2, 0);
    SetSubitemState(node[1], 0, 2, 0);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov257_FinishIfSubFlagClear);
}
