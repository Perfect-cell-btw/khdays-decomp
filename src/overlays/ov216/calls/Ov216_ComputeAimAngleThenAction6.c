extern void VEC_Subtract(void *a, void *b, void *out);
extern int VEC_Normalize(void *dst, void *src);
extern int func_020050b4(int x, int y);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov216_stEnterSetFlag40(void);

void Ov216_ComputeAimAngleThenAction6(int *node) {
    int *state = (int *)node[1];
    int v[3];
    int r;
    if (state[2] == 0) {
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)(node + 8), 0);
        return;
    }
    VEC_Subtract((void *)(state[2] + 0x190), (void *)(*state + 0xb0), v);
    v[1] = 0;
    state[0x12] = VEC_Normalize(v, v);
    r = func_020050b4(v[0], v[2]);
    state[0x13] = r;
    state[0x11] = r;
    Ov107_PostTagUpdate(*state, 3, 0);
    Ov107_BuildAndSendUpdate(*state, 0x144, 6, state[4]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov216_stEnterSetFlag40);
}
