/* State step: derives the speed from the owner's frame step, sets bit 0x40 in the high byte of the
 * actor's flags, starts the slam animation, posts a pose, clears the hit flags and timer, sends a
 * state update and installs the slam step. */

extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov140_SlamTick(void);
void Ov140_stateSetFlagEffect_2(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 5;
    }
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x390), 4, 0);
    Ov107_PostTagUpdate(*state, 0xc, 0);
    *(signed char *)((char *)state + 0x54) = 0;
    Ov107_BuildAndSendUpdate(*state, 0x11f, 6, state[0x13]);
    *(signed char *)((char *)state + 0x55) = 0;
    state[0xf] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_SlamTick);
}
