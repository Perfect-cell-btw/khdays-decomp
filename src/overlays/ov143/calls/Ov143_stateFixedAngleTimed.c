extern void Ov143_StoreVec3AndSetHw60HighBit0();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern short data_0203d210[];
extern void Ov143_AiStep_QueueAction2WhenFree(void);
void Ov143_stateFixedAngleTimed(int *node) {
    int *state = (int *)node[1];
    int t = state[0xc] + *(int *)(*node + 0x2c);
    state[0xc] = t;
    if (t < 0x999) return;
    {
        int buf[3];
        int angle = (int)(((unsigned)(((long long)(int)(unsigned)state[2] * 0x28be60db9391LL +
                           0x80000000000LL) >> 0x20) << 4) >> 0x10) >> 4;
        buf[0] = (int)data_0203d210[angle * 2];
        buf[1] = 0;
        buf[2] = (int)data_0203d210[angle * 2 + 1];
        Ov143_StoreVec3AndSetHw60HighBit0(*(int *)(*state + 0x3c8), *(int *)(*state + 0x394) + 0x14, buf);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov143_AiStep_QueueAction2WhenFree);
}
