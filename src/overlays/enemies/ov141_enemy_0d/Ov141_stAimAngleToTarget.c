extern void Ov107_PostTagUpdate();
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int z);
extern void Ov107_StartAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov141_stAdvanceProjectilePose(void);

void Ov141_stAimAngleToTarget(int *node) {
    int *state = (int *)node[1];
    int buf[3];
    Ov107_PostTagUpdate(*state, 3, 0);
    {
        int p = state[0xe];
        if (p != 0) {
            int r;
            VEC_Subtract((void *)(p + 0x190), (void *)(*state + 0xb0), buf);
            r = func_020050b4(buf[0], buf[2]);
            state[3] = r;
            state[2] = r;
        }
    }
    Ov107_StartAnim(*(int *)(*state + 0x3cc), 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov141_stAdvanceProjectilePose);
}
