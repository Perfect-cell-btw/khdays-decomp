/* AI step: advances the timer and rotates the offset; when the animation ends, posts pose 0xe and
 * continues with the slam. */

extern void MTX_RotY33_();
extern void MTX_MultVec33();
extern void Ov107_PostTagUpdate();
extern void Ov276_startAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern short data_0203d210[];
extern void Ov276_SlamTick(void);
void Ov276_stateFixedAngleMatrix_3(int *node) {
    int *state = (int *)node[1];
    int mtx[9];
    int angle;
    state[0x13] = state[0x13] + *(int *)(*node + 0x2c);
    angle = (int)(((unsigned)(((long long)(int)(unsigned)state[0x10] * 0x28be60db9391LL +
                   0x80000000000LL) >> 0x20) << 4) >> 0x10) >> 4;
    MTX_RotY33_(mtx, (int)data_0203d210[angle * 2], (int)data_0203d210[angle * 2 + 1]);
    MTX_MultVec33(*(int *)(*state + 0x470) + 0x2c, mtx, state + 4);
    if (*(unsigned char *)(state[1] + 0xad) == 0) {
        Ov107_PostTagUpdate(*state, 0xe, 0);
        Ov276_startAnim(*state, 0xb);
        *(signed char *)((char *)state + 0x62) = 0;
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov276_SlamTick);
    }
}
