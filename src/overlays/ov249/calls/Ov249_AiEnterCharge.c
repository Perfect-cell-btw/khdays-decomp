extern void ScaleVec3Fx12();
extern void VEC_Subtract();
extern void Ov107_MoveNodeAndRelayout();
extern void Ov107_PostTagUpdate();
extern void Ov249_startAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern short data_0203d210[];
extern void Ov249_ChargeTick(void);
void Ov249_AiEnterCharge(int *node) {
    int *state = (int *)node[1];
    if (state[2] != 0) {
        int vec[3];
        int angle = (int)(((unsigned)(((long long)(int)(unsigned)state[0x10] * 0x28be60db9391LL +
                           0x80000000000LL) >> 0x20) << 4) >> 0x10) >> 4;
        vec[0] = (int)data_0203d210[angle * 2];
        vec[1] = 0;
        vec[2] = (int)data_0203d210[angle * 2 + 1];
        ScaleVec3Fx12(*(int *)(*state + 0x4a0), vec, vec);
        VEC_Subtract(state[2] + 0x190, vec, vec);
        Ov107_MoveNodeAndRelayout(*state, vec);
        state[2] = 0;
    }
    Ov107_PostTagUpdate(*state, 0x13, 0);
    Ov249_startAnim(*state, 0xd);
    state[0x13] = 0;
    *(signed char *)((char *)state + 0x61) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov249_ChargeTick);
}
