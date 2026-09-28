extern void VEC_Subtract(void *a, void *b, void *out);
extern int VEC_Normalize(void *dst, void *src);
extern void ScaleVec3Fx12(int scale, void *src, void *dst);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);

struct vec3 { int a, b, c; };
extern struct vec3 data_02041dc8;

void Ov174_ConfigAimVecThenAction8(int *node) {
    int *state = (int *)node[1];
    *(struct vec3 *)(state + 0xb) = data_02041dc8;
    if (state[4] != 0) {
        VEC_Subtract((void *)(*state + 0x74), (void *)(state[4] + 0x74), state + 0xb);
        state[0xc] = 0;
    }
    VEC_Normalize(state + 0xb, state + 0xb);
    ScaleVec3Fx12(0x800, state + 0xb, state + 0xb);
    Ov107_PostTagUpdate(*state, 6, 0);
    Ov107_BuildAndSendUpdate(*state, 0x141, 8, state[2]);
    state[0x16] = 0x6000;
    *(signed char *)(*state + 0x1c7) = 0xb;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
