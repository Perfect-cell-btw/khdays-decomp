extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov194_DecideTick(void);
void Ov194_stDiv15Store_ccecc(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[5] = v / 15;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov194_DecideTick);
}
