extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov242_AiWaypointWait(void);

void Ov242_ConfigSubStateThenAdvanceSlot(int *node) {
    int *n0 = (int *)node[0];
    int *state = (int *)node[1];
    state[0xb] -= n0[0xb];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*state, 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov242_AiWaypointWait);
}
