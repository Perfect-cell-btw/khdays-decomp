extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov251_BeginSteerSweep(void);
void Ov251_stateAnimNegateClamp(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 0x11, 0);
    state[0x1e] = -state[0x1e];
    state[0x20] = -state[0x20];
    if (state[0x1f] > 0) state[0x1f] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov251_BeginSteerSweep);
}
