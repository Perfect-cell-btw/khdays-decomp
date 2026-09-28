/* Show the two "reaction ready" subitem icons (slots 2 and 0) and register the reaction think
 * callback, while the target lock (node[1]+0xad) is clear. */
extern void SetSubitemState(int obj, int slot, int a, int b);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov257_HideReactionIcons(void);

void Ov257_ShowReactionReady(int param_1) {
    int *node = *(int **)(param_1 + 4);
    if (*(unsigned char *)(node[1] + 0xad) != 0) {
        return;
    }
    SetSubitemState(node[1], 2, 1, 1);
    SetSubitemState(node[1], 0, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov257_HideReactionIcons);
}
