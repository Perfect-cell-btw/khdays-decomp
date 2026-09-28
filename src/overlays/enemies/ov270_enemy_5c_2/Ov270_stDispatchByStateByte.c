struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov270_stSetFlags86Clear(void);
extern void Ov270_stSetFlags82ClearC(void);
extern void Ov270_SetPose1ThenAdvanceSlot(void);
extern void Ov270_stateAnimAimAtTarget(void);
extern void Ov270_PoseClearField30ThenAdvance(void);
extern void Ov270_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov270_AiEnterCharge(void);
extern void Ov270_ResetReactionAi(void);
extern void Ov270_stateAnimPairCallback(void);
extern void Ov270_AiEndWithUpdate(void);
extern void Ov270_stateAimAnimEffect(void);
extern void Ov270_stateAimAnimEffect_2(void);
extern void Ov270_AiEnterTrackOffset(void);
extern void Ov270_AiEnterTrackOffsetB(void);
extern void Ov270_stateAnimEffect(void);
extern void Ov270_AiEnterCombo(void);

void Ov270_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov270_stSetFlags86Clear); break;
        case 1: SetIndexedSlot(node, 1, Ov270_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov270_SetPose1ThenAdvanceSlot); break;
        case 5: SetIndexedSlot(node, 1, Ov270_stateAnimAimAtTarget); break;
        case 4: SetIndexedSlot(node, 1, Ov270_PoseClearField30ThenAdvance); break;
        case 3: SetIndexedSlot(node, 1, Ov270_ConfigHw60C5af8ThenClearRequest); break;
        case 6: SetIndexedSlot(node, 1, Ov270_AiEnterCharge); break;
        case 7: SetIndexedSlot(node, 1, Ov270_ResetReactionAi); break;
        case 8: SetIndexedSlot(node, 1, Ov270_stateAnimPairCallback); break;
        case 9: SetIndexedSlot(node, 1, Ov270_AiEndWithUpdate); break;
        case 10: SetIndexedSlot(node, 1, Ov270_stateAimAnimEffect); break;
        case 11: SetIndexedSlot(node, 1, Ov270_stateAimAnimEffect_2); break;
        case 12: SetIndexedSlot(node, 1, Ov270_AiEnterTrackOffset); break;
        case 13: SetIndexedSlot(node, 1, Ov270_AiEnterTrackOffsetB); break;
        case 14: SetIndexedSlot(node, 1, Ov270_stateAnimEffect); break;
        case 15: SetIndexedSlot(node, 1, Ov270_AiEnterCombo); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
