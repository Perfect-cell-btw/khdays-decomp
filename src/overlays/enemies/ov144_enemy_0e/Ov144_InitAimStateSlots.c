/* Init state: clears the current and pending actions, records the actor's velocity pointer and
 * installs the first action, the dispatcher and the orientation step. */

extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov144_stSetDispFlags86(void);
extern void Ov144_SubStateDispatch(void);
extern void Ov144_OrientationTick(void);

void Ov144_InitAimStateSlots(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    state[2] = *state + 0xb0;
    SetIndexedSlot(node, 1, Ov144_stSetDispFlags86);
    SetIndexedSlot(node, 0, Ov144_SubStateDispatch);
    SetIndexedSlot(node, 2, Ov144_OrientationTick);
}
