struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov269_stSetFlags86Clear(void);
extern void Ov269_stSetFlags82ClearC(void);
extern void Ov269_SetPose1ThenAdvanceSlot(void);
extern void Ov269_stateAnimAimAtTarget(void);
extern void Ov269_PoseClearField30ThenAdvance(void);
extern void Ov269_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov269_AiEnterCharge(void);
extern void Ov269_ResetReactionAi(void);
extern void Ov269_stateAnimPairCallback(void);
extern void Ov269_AiEndWithUpdate(void);
extern void Ov269_stateAimAnimEffect(void);
extern void Ov269_stateAimAnimEffect_2(void);
extern void Ov269_AiEnterTrackOffset(void);
extern void Ov269_AiEnterTrackOffsetB(void);
extern void Ov269_stateAnimEffect(void);
extern void Ov269_AiEnterCombo(void);

void Ov269_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov269_stSetFlags86Clear); break;
        case 1: SetIndexedSlot(node, 1, Ov269_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov269_SetPose1ThenAdvanceSlot); break;
        case 5: SetIndexedSlot(node, 1, Ov269_stateAnimAimAtTarget); break;
        case 4: SetIndexedSlot(node, 1, Ov269_PoseClearField30ThenAdvance); break;
        case 3: SetIndexedSlot(node, 1, Ov269_ConfigHw60C5af8ThenClearRequest); break;
        case 6: SetIndexedSlot(node, 1, Ov269_AiEnterCharge); break;
        case 7: SetIndexedSlot(node, 1, Ov269_ResetReactionAi); break;
        case 8: SetIndexedSlot(node, 1, Ov269_stateAnimPairCallback); break;
        case 9: SetIndexedSlot(node, 1, Ov269_AiEndWithUpdate); break;
        case 10: SetIndexedSlot(node, 1, Ov269_stateAimAnimEffect); break;
        case 11: SetIndexedSlot(node, 1, Ov269_stateAimAnimEffect_2); break;
        case 12: SetIndexedSlot(node, 1, Ov269_AiEnterTrackOffset); break;
        case 13: SetIndexedSlot(node, 1, Ov269_AiEnterTrackOffsetB); break;
        case 14: SetIndexedSlot(node, 1, Ov269_stateAnimEffect); break;
        case 15: SetIndexedSlot(node, 1, Ov269_AiEnterCombo); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
