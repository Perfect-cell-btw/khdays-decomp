extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov144_AdvanceTick(void);

void Ov144_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*state, 7, 1);
    Ov107_StartAnim(*(int *)(*state + 0x394), 1, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_AdvanceTick);
}
