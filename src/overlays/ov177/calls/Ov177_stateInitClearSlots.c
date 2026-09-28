struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov177_dispatchByStatusByte(void);
extern void Ov177_ConfigHw60CopyVec3ConstThenAdvance(void);
extern void Ov177_SetPoseVecOrTransform(void);
void Ov177_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[1] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov177_dispatchByStatusByte);
    SetIndexedSlot(node, 1, Ov177_ConfigHw60CopyVec3ConstThenAdvance);
    SetIndexedSlot(node, 2, Ov177_SetPoseVecOrTransform);
}
