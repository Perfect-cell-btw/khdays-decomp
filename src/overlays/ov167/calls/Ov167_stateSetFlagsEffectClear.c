struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov167_stateTimerToggleFlags(void);
void Ov167_stateSetFlagsEffectClear(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x46) << 0x18) >> 0x10));
    }
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x49, state[2]);
    state[0x12] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov167_stateTimerToggleFlags);
}
