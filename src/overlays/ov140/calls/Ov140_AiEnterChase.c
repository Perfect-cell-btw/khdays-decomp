extern int Ov107_FindNearestObject(int a, int b);
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov140_ApproachEntry(void);
void Ov140_AiEnterChase(int *node) {
    int *state = (int *)node[1];
    int t = Ov107_FindNearestObject(*state, 0);
    state[1] = t;
    if (t == 0) {
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)(node + 8), 0);
        return;
    }
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 10;
    }
    Ov107_PostTagUpdate(*state, 2, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_ApproachEntry);
}
