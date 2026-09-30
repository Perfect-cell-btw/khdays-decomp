/* State step: moves along the heading at a fixed speed until the timer (advanced by the owner's
 * frame step) reaches 1.0, then clears the model's movement byte (+0xa8) and installs the strafe
 * step. */

extern void ScaleVec3Fx12();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern short data_0203d210[];
extern void Ov152_StrafePick(void);
void Ov152_stateFixedAngleMove(int *node) {
    int *state = (int *)node[1];
    int buf[3];
    int angle = (int)(((unsigned)(((long long)(int)(unsigned)state[2] * 0x28be60db9391LL +
                       0x80000000000LL) >> 0x20) << 4) >> 0x10) >> 4;
    buf[0] = (int)data_0203d210[angle * 2];
    buf[1] = 0;
    buf[2] = (int)data_0203d210[angle * 2 + 1];
    ScaleVec3Fx12(0x300, buf, state + 6);
    {
        int t = state[0xc] + *(int *)(*node + 0x2c);
        state[0xc] = t;
        if (t < 0x1000) return;
    }
    *(char *)(*(int *)(*state + 0x384) + 0xa8) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov152_StrafePick);
}
