/* Node initialiser of the ov241 enemy (x3: ov241/242/243): resets the actor's +0x1c6 state and
 * +0x1c7 sub-state request, clears the +4/+8 heading pair (chained, which pins the zero's
 * register), points +0xc at the actor's +0xb0 pose and installs the three slot handlers
 * (1: 020d075c, 0: 020d0514, 2: 020d06ec). */
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov243_stSetDispFlags86(void);
extern void Ov243_SubStateDispatch(void);
extern void Ov243_UpdateFacing(void);
void Ov243_InitNode(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    state[2] = state[1] = 0;
    state[3] = *state + 0xb0;
    SetIndexedSlot(node, 1, Ov243_stSetDispFlags86);
    SetIndexedSlot(node, 0, Ov243_SubStateDispatch);
    SetIndexedSlot(node, 2, Ov243_UpdateFacing);
}
