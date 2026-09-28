extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov241_WalkTick(void);

void Ov241_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 1, 1);
    Ov107_StartAnim(*(int *)(*state + 0x39c), 0, 1);
    *(unsigned char *)((char *)state + 0x40) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov241_WalkTick);
}
