struct bf { unsigned b : 8; };
struct blk16 { int a, b, c, d; };
extern void Obj_SetFourWords(void *p, int a, int b, int c, int d);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov172_stDispatchByStateByte_ccbcc(void);
extern void Ov172_stDivStoreField(void);
extern void Ov172_stateSetFlagsClearBit(void);
void Ov172_stateInitTransformSlots(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    state[2] = *state + 0x74;
    state[3] = 0;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    Obj_SetFourWords(state + 0x19, 0, 0, 0, 0);
    *(struct blk16 *)(state + 0x1d) = *(struct blk16 *)(state + 0x19);
    SetIndexedSlot(node, 0, Ov172_stDispatchByStateByte_ccbcc);
    SetIndexedSlot(node, 1, Ov172_stateSetFlagsClearBit);
    SetIndexedSlot(node, 2, Ov172_stDivStoreField);
}
