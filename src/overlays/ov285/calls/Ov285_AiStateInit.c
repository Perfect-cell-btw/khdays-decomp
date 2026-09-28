/* Resets the action state, caches the position pointers, sets stance bits 0x16 and installs the AI
 * slots. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov285_stateSetFlagsClearBit(void);
extern void Ov285_DispatchSubStateByte(void);
extern void Ov285_ApplyFacingAndFlushMove(void);

void Ov285_AiStateInit(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    state[0x3] = *state + 0xb0;
    state[0x4] = *state + 0x74;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 22) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov285_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, Ov285_DispatchSubStateByte);
    SetIndexedSlot(node, 2, Ov285_ApplyFacingAndFlushMove);
}
