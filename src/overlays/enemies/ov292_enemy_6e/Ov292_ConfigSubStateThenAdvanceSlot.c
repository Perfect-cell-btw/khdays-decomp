/* AI step: posts pose 1, seeks the current path point and continues. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov292_SeekPointAtIndex(int *state);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void func_ov292_020d45bc(void);

void Ov292_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 1, 1);
    Ov292_SeekPointAtIndex(state);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), func_ov292_020d45bc);
}
