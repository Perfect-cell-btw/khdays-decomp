extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int y);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov151_AiTrackOffsetUntilLanded(void);

void Ov151_Pose3AimYawAdvance(int *node) {
    int *state = (int *)node[1];
    int local[3];
    Ov107_PostTagUpdate(*state, 3, 0);
    if (state[0xf] != 0) {
        VEC_Subtract((void *)(state[0xf] + 0x190), (void *)state[0x10], local);
        int r = func_020050b4(local[0], local[2]);
        state[3] = r;
        state[2] = r;
    }
    Ov107_StartAnim(*(int *)(*state + 0x3cc), 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov151_AiTrackOffsetUntilLanded);
}
