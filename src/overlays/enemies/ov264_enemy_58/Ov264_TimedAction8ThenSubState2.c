extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);

void Ov264_TimedAction8ThenSubState2(int *node) {
    int *state = (int *)node[1];
    state[0x14] += *(int *)(*node + 0x2c);
    if (*(unsigned char *)((char *)state + 0x70) == 0 && state[0x14] >= 0x7f8) {
        Ov107_BuildAndSendUpdate(*state, 0x15d, 8, state[4]);
        *(unsigned char *)((char *)state + 0x70) = 1;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    *(signed char *)(*state + 0x1c7) = 2;
    state[0x15] = *(int *)(*node + 0x2c);
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
