struct v3 { int x, y, z; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void VEC_Subtract(const void *a, const void *b, void *c);
extern int func_020050b4(int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov190_CopyScaleVec3GuardedThenAdvance(void);

void Ov190_ComputeTargetDeltaThenAdvance(int *node) {
    int *state = (int *)node[1];
    struct v3 buf;
    Ov107_PostTagUpdate(*state, 3, 0);
    int obj = state[0xe];
    if (obj != 0) {
        VEC_Subtract((const void *)(obj + 0x190), (const void *)(*state + 0xb0), &buf);
        state[4] = state[5] = func_020050b4(buf.x, buf.z);
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov190_CopyScaleVec3GuardedThenAdvance);
}
