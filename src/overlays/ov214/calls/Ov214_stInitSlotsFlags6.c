struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov214_stSetFlags86Clear3ac(void);
extern void Ov214_stDispatchByStateByte(void);
extern void Ov214_stUpdateMatrixAdvance(void);

void Ov214_stInitSlotsFlags6(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x3ac) + 8))->b &= ~1;
    state[4] = *state + 0xb0;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov214_stSetFlags86Clear3ac);
    SetIndexedSlot(node, 0, Ov214_stDispatchByStateByte);
    SetIndexedSlot(node, 2, Ov214_stUpdateMatrixAdvance);
}
