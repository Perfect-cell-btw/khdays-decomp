extern void SetIndexedSlot(void *obj, int idx, void *value);
void Ov124_stDiv5Store(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[8] = v / 5;
    if (*(unsigned char *)state[12] != 0) return;
    *(signed char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
