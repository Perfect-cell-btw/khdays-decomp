extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov133_ReactWhenTargetInReach(void);
void Ov133_stDiv30Store(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[5] = v / 30;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov133_ReactWhenTargetInReach);
}
