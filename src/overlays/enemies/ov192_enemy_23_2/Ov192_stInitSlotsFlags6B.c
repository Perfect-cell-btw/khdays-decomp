struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov192_DispatchSubStateByte(void);
extern void Ov192_stSetFlagsC6ClearBits(void);
extern void Ov192_stUpdateOrientMatrix(void);

void Ov192_stInitSlotsFlags6B(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    state[2] = *state + 0xb0;
    state[3] = *state + 0x74;
    state[1] = *(int *)(*state + 0x384) + 0xad;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 0, Ov192_DispatchSubStateByte);
    SetIndexedSlot(node, 1, Ov192_stSetFlagsC6ClearBits);
    SetIndexedSlot(node, 2, Ov192_stUpdateOrientMatrix);
}
