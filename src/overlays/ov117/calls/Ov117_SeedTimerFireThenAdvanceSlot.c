extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov117_AimAtTarget(void);
void Ov117_SeedTimerFireThenAdvanceSlot(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[10] = v / 10;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov117_AimAtTarget);
}
