extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov293_stIdlePose10Advance(void);

void Ov293_ConfigSubStateThenAdvanceSlot(int *node) {
    int *n0 = (int *)node[0];
    int *state = (int *)node[1];
    state[0x10] += n0[0xb];
    if (state[0x10] > 0x4800) {
        *(unsigned char *)(*(int *)(*state + 0x384) + 0xa8) = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov293_stIdlePose10Advance);
    }
}
