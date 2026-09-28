struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov149_stTickAimTimer(void);

void Ov149_stSetFlagsEffectClear82(int *node) {
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
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov149_stTickAimTimer);
}
