struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov192_stTickAimTimerB(void);

void Ov192_stSetFlags82ClearC(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10));
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xc;
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, state[3]);
    state[0xb] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov192_stTickAimTimerB);
}
