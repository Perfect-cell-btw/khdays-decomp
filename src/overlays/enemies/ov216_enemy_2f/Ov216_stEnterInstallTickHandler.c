extern void BindAnimTrack(int a, int b, int c, int d);
extern void SetIndexedSlot(int node, int slot, void *cb);
extern void Ov216_tickActiveEntryCooldowns(void);
extern void Ov216_EmptyTickHandler(void);

void Ov216_stEnterInstallTickHandler(int node) {
    int *state = *(int **)(node + 4);
    *(void **)(*state + 0x78) = (void *)Ov216_tickActiveEntryCooldowns;
    *(int **)(*state + 0x84) = state;
    *(unsigned *)(*state + 0x5c) &= ~2;
    BindAnimTrack(*(int *)(*state + 0x88), 0, *(int *)(*state + 0x88) + 0xe0, 0);
    {
        int i = 0;
        if (*(int *)(*state + 0x8c) > 0) {
            int off = 0;
            do {
                int base = *(int *)(*state + 0x90);
                i++;
                *(int *)(base + off) = 0;
                *(int *)(base + off + 4) = 0;
                off += 0x38;
            } while (i < *(int *)(*state + 0x8c));
        }
    }
    state[1] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), (void *)Ov216_EmptyTickHandler);
}
