extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov298_AiLockStep(void);

void Ov298_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 0, 1);
    state[0x14] = 0x900;
    state[0xe] = 0x27d8;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov298_AiLockStep);
}
