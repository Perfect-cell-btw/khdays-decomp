/* Init state: clears the current and pending actions, clears bit 0 of the model's flag byte,
 * records pointers to the actor's velocity and position, sets the initial flag bits and installs
 * the first action, the dispatcher and the heading step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov247_SetHwFlagsAndDispatch(void);
extern void Ov247_AiDispatchAction(void);
extern void Ov247_AiApplyHeadingAndNormal(void);

void Ov247_BeginPhasedReaction(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x384) + 8))->b &= ~1;
    state[0x13] = *state + 0xb0;
    state[0x14] = *state + 0x74;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov247_SetHwFlagsAndDispatch);
    SetIndexedSlot(node, 0, Ov247_AiDispatchAction);
    SetIndexedSlot(node, 2, Ov247_AiApplyHeadingAndNormal);
}
