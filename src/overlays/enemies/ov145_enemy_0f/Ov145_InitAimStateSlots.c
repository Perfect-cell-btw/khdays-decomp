extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov145_stSetDispFlags86(void);
extern void Ov145_SubStateDispatch(void);
extern void Ov145_OrientationTick(void);

void Ov145_InitAimStateSlots(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    state[2] = *state + 0xb0;
    SetIndexedSlot(node, 1, Ov145_stSetDispFlags86);
    SetIndexedSlot(node, 0, Ov145_SubStateDispatch);
    SetIndexedSlot(node, 2, Ov145_OrientationTick);
}
