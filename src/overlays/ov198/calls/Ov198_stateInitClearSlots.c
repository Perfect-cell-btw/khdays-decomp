struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov198_dispatchByStatusByteReset(void);
extern void Ov198_ResetPoseAndFlags(void);
extern void Ov198_PublishVelocity_Step(void);
void Ov198_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[1] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov198_dispatchByStatusByteReset);
    SetIndexedSlot(node, 1, Ov198_ResetPoseAndFlags);
    SetIndexedSlot(node, 2, Ov198_PublishVelocity_Step);
}
