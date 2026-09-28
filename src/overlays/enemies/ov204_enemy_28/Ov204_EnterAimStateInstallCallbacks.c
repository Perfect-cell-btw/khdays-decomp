/* Init state: clears the current and pending actions, clears bit 0 of the model's flag byte,
 * records pointers to the actor's velocity, position and model busy flag, sets the initial flag
 * bits and installs the first action, the dispatcher and the motion step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov204_stateSetFlagsClearBit(void);
extern void Ov204_DispatchSubStateByte(void);
extern void Ov204_AdvanceMotionPublish(void);

void Ov204_EnterAimStateInstallCallbacks(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    state[0x8] = *state + 0xb0;
    state[0x9] = *state + 0x74;
    state[0xa] = *(int *)(*state + 0x384) + 0xad;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov204_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, Ov204_DispatchSubStateByte);
    SetIndexedSlot(node, 2, Ov204_AdvanceMotionPublish);
}
