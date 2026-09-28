struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov171_dispatchByStatusByte(void);
extern void Ov171_ConfigHw60CopyVec3ConstTo30ThenAdvance(void);
extern void Ov171_SetPoseVecFromStateOrConst(void);
void Ov171_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[2] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov171_dispatchByStatusByte);
    SetIndexedSlot(node, 1, Ov171_ConfigHw60CopyVec3ConstTo30ThenAdvance);
    SetIndexedSlot(node, 2, Ov171_SetPoseVecFromStateOrConst);
}
