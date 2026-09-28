extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov114_AiSwingTick(void);

void Ov114_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 0xb, 0);
    Ov107_BuildAndSendUpdate(*state, 0x112, 4, state[1]);
    state[0x11] = 0;
    *(unsigned char *)((char *)state + 0x49) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov114_AiSwingTick);
}
