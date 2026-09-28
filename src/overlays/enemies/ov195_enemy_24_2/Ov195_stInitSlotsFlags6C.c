/* Init state: clears the current and pending actions, clears bit 0 of the model's flag byte,
 * records pointers to the actor's velocity and position, sets the initial flag bits and installs
 * the first action, the dispatcher and the spin step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov195_stSetFlags86Clear(void);
extern void Ov195_stDispatchByStateByte(void);
extern void Ov195_StepSpinAndSwapPose(void);

void Ov195_stInitSlotsFlags6C(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    state[0xf] = *state + 0xb0;
    state[0x10] = *state + 0x74;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov195_stSetFlags86Clear);
    SetIndexedSlot(node, 0, Ov195_stDispatchByStateByte);
    SetIndexedSlot(node, 2, Ov195_StepSpinAndSwapPose);
}
