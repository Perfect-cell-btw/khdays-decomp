extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov292_SeekPointAtIndex(int *state);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov292_SetSubState4UnlessFlagAd(void);

void Ov292_ConfigSubStateThenAdvanceSlot_3(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 3, 0);
    Ov292_SeekPointAtIndex(state);
    state[0xc] = 0x100;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov292_SetSubState4UnlessFlagAd);
}
