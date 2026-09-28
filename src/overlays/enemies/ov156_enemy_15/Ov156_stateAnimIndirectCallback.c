extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov156_020ced90[];
extern void Ov156_ThrowWindup(void);
void Ov156_stateAnimIndirectCallback(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();
    Ov107_PostTagUpdate(*state, 3, 0);
    state[0xb] = 0;
    *(signed char *)((char *)state + 0x38) = 0;
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[0xc] = v / 5;
    }
    pp = pair;
    pp[1] = data_ov156_020ced90[1];
    pp[0] = data_ov156_020ced90[0];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov156_ThrowWindup);
}
