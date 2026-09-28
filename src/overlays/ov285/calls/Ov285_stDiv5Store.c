extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov285_Chase_DecideAttack(void);
void Ov285_stDiv5Store(int *node) {
    int result = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    result = result / 5;
    state[5] = result;
    Ov107_PostTagUpdate(*state, 0, 1, result);
    state[10] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov285_Chase_DecideAttack);
}
