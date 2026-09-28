struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov199_stateSetFlagsClearBit(void);
extern void Ov199_EnterAttackFacingTarget(void);
extern void Ov199_AiEnterHold(void);
extern void Ov199_BeginMoveOrRequestState2(void);
extern void Ov199_SpawnTrailOrFail(void);
extern void Ov199_SetPose5ThenAdvanceSlot(void);
extern void Ov199_Action4bCallback(void);
extern void Ov199_Action49Callback(void);
extern void Ov199_AiEnterFaceTarget(void);

void Ov199_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x86;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov199_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov199_EnterAttackFacingTarget);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov199_AiEnterHold);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov199_BeginMoveOrRequestState2);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov199_SpawnTrailOrFail);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov199_SetPose5ThenAdvanceSlot);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov199_Action4bCallback);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov199_Action49Callback);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov199_AiEnterFaceTarget);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
