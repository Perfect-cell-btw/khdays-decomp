/* State step: derives the speed from the owner's frame step, sets bit 0x40 in the high byte of the
 * actor's flags, starts the slam animation, posts a pose, clears the hit flags and timer and
 * installs the slam step. */

extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov204_SlamTick(void);
void Ov204_stateSetFlagEffect(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[0xf] = v / 5;
    }
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x390), 4, 0);
    Ov107_PostTagUpdate(*state, 0xc, 0);
    *(signed char *)((char *)state + 0x45) = 0;
    *(signed char *)((char *)state + 0x44) = 0;
    state[0xb] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov204_SlamTick);
}
