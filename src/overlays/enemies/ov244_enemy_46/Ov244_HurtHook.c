/* Enemy hurt hook: cancel the current action (mode 1), send the second pair of
 * knockback values from the table as a 4-byte message to the model's handler at
 * +0x24 (when it has one), clear the hit accumulator at +0x1c and register the
 * recovery handler. */
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov244_020d3724[];
extern void Ov244_LungeBiteTick(void);

void Ov244_HurtHook(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();

    Ov107_PostTagUpdate(*state, 1, 0);

    pp = pair;
    pp[1] = data_ov244_020d3724[3];
    pp[0] = data_ov244_020d3724[2];

    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);

    state[7] = 0;

    SetIndexedSlot(node, *(signed char *)(node + 8), Ov244_LungeBiteTick);
}
