/* State step: sets bits 0x82 in the high byte of the actor's flags (+0x60) and bit 0 of +0x1ae,
 * clears bit 0 of its model's flag byte, clears the timer, sends a state update and installs the
 * aiming timer step. */

struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov150_stTickAimTimer(void);

void Ov150_stSetFlagsEffectClear82(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10));
    }
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    state[0xc] = 0;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, state[0x10]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov150_stTickAimTimer);
}
