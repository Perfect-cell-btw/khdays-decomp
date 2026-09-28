struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov157_CommitPendingSubStateAndDispatch(void);
extern void Ov157_ConfigHw60CopyVec3ConstToCThenAdvance(void);
extern void Ov157_AiApplyMoveVector(void);
void Ov157_stateInitClearSlots(int *node) {
    int *state = (int *)node[1];
    state[2] = *state + 0xb0;
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    SetIndexedSlot(node, 0, Ov157_CommitPendingSubStateAndDispatch);
    SetIndexedSlot(node, 1, Ov157_ConfigHw60CopyVec3ConstToCThenAdvance);
    SetIndexedSlot(node, 2, Ov157_AiApplyMoveVector);
}
