extern void Ov107_PostTagUpdate();
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov149_020d074c[];
extern void Ov149_stateFixedAngleTimed(void);
void Ov149_stateAnimCallbackEffect(int *node) {
    int *state = (int *)node[1];
    unsigned short buf[2];
    unsigned short *pp;
    void (*cb)();
    if (state[5] >= 0x100) return;
    pp = buf;
    pp[1] = data_ov149_020d074c[5];
    pp[0] = data_ov149_020d074c[4];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 10;
    }
    Ov107_PostTagUpdate(*state, 5, 0);
    state[0xc] = 0;
    *(signed char *)((char *)state + 0x48) = 0;
    Ov107_BuildAndSendUpdate(*state, 0x14e, 4, *(int *)(*state + 0x394) + 0x14);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov149_stateFixedAngleTimed);
}
