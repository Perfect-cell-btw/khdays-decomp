/* State step: once the counter is below 0x100, sends an animation pair from the overlay's table to
 * the actor's event callback, derives the speed from the owner's frame step, posts pose 5, resets
 * the timer, sends an effect update and installs the summon step. */

extern void Ov107_PostTagUpdate();
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov152_020d64b4[];
extern void Ov152_SummonTick(void);
void Ov152_stateAnimCallbackEffect(int *node) {
    int *state = (int *)node[1];
    unsigned short buf[2];
    unsigned short *pp;
    void (*cb)();
    if (state[5] >= 0x100) return;
    pp = buf;
    pp[1] = data_ov152_020d64b4[5];
    pp[0] = data_ov152_020d64b4[4];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 10;
    }
    Ov107_PostTagUpdate(*state, 5, 0);
    state[0xc] = 0;
    *(signed char *)((char *)state + 0x4c) = 0;
    Ov107_BuildAndSendUpdate(*state, 0x14f, 4, *(int *)(*state + 0x394) + 0x14);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov152_SummonTick);
}
