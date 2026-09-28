struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov176_dispatchByStatusByte(void);
extern void Ov176_ConfigHw60CopyVec3ConstThenAdvance(void);
extern void Ov176_SetPoseVecOrTransform(void);
void Ov176_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[1] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov176_dispatchByStatusByte);
    SetIndexedSlot(node, 1, Ov176_ConfigHw60CopyVec3ConstThenAdvance);
    SetIndexedSlot(node, 2, Ov176_SetPoseVecOrTransform);
}
