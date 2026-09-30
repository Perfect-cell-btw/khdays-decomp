/* Timed step: advances the timer by the owner's frame step until it passes 0xd48; then sets bit 7
 * and clears bit 0 of the high flag byte, clears the pending action and clears the step handler. */

struct hw { unsigned short lo:8, hi:8; };

extern void SetIndexedSlot(int node, int slot, void *cb);

void Ov217_stTimerSetFlag80ClearBit0(int *param_1) {
    int *state = (int *)param_1[1];
    int acc = state[0x14] + *(int *)(*param_1 + 0x2c);
    state[0x14] = acc;
    if (acc < 0xd48) return;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10));
    }
    ((struct hw *)(*state + 0x60))->hi &= ~1;
    *(char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 8), 0);
}
