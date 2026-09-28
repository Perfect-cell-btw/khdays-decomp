/* AI step: posts pose 0, resets the idle timers and continues with the idle tick. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov297_IdleTick(void);

void Ov297_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 0, 1);
    state[0x14] = 0x900;
    state[0xe] = 0xff0;
    state[0xf] = 0;
    state[0x1e] = 0;
    *(unsigned char *)((char *)state + 0x93) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov297_IdleTick);
}
