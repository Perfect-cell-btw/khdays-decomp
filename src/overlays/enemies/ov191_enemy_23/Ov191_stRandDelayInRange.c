extern int RandNextScaled(int);
extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov191_stRandDelayInRange(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)state[1] == 0) {
        int lo = *(int *)(*state + 0x224);
        int hi = *(int *)(*state + 0x228);
        int d = hi - lo;
        if (d < 0) d = -d;
        state[0xd] = lo + RandNextScaled(d + 1);
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)(node + 8), (void *)0);
    }
}
