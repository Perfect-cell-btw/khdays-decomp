extern int RandNextScaled(int max);
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov163_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)state[0x16] != 0) return;
    int base = *(int *)(*state + 0x224);
    int d = *(int *)(*state + 0x228) - base;
    if (d < 0) d = -d;
    state[0xd] = base + RandNextScaled(d + 1);
    *(signed char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
