extern int Ov107_FindNearestObject();
extern void VEC_Subtract();
extern int func_020050b4();
extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov195_TickSpinRetreat(void);
void Ov195_stateAimAnimEffect_2(int *node) {
    int *state = (int *)node[1];
    int buf[3];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[5] = v / 3;
    }
    {
        int t = Ov107_FindNearestObject(*state, 0);
        state[2] = t;
        if (t != 0) {
            VEC_Subtract(t + 0x190, *state + 0xb0, buf);
            state[4] = func_020050b4(buf[0], buf[2]);
        }
    }
    Ov107_PostTagUpdate(*state, 0xb, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 3, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov195_TickSpinRetreat);
}
