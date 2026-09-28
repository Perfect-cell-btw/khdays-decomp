struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov301_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (!(((struct hw60 *)(*state + 0x60))->lo & 1)) return;
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    Ov107_PostTagUpdate(*state, 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
