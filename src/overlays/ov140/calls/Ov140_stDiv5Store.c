extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov140_ApproachDecision(void);
void Ov140_stDiv5Store(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[4] = v / 5;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_ApproachDecision);
}
