struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov195_stSetFlags86Clear(void);
extern void Ov195_stSetFlags82ClearC(void);
extern void Ov195_stDiv15Store(void);
extern void Ov195_stateAnimAimAtTarget(void);
extern void Ov195_stDivPoseEffect(void);
extern void Ov195_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov195_AiEnterCharge(void);
extern void Ov195_ResetReactionAi(void);
extern void Ov195_stateAnimPairCallback(void);
extern void Ov195_AiEndWithUpdate(void);
extern void Ov195_stateAimAnimEffect(void);
extern void Ov195_stateAimAnimEffect_2(void);
extern void Ov195_AiEnterTrackOffset(void);
extern void Ov195_AiEnterTrackOffsetB(void);
extern void Ov195_stateAnimEffect(void);
extern void Ov195_AiEnterCombo(void);

void Ov195_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov195_stSetFlags86Clear); break;
        case 1: SetIndexedSlot(node, 1, Ov195_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov195_stDiv15Store); break;
        case 5: SetIndexedSlot(node, 1, Ov195_stateAnimAimAtTarget); break;
        case 4: SetIndexedSlot(node, 1, Ov195_stDivPoseEffect); break;
        case 3: SetIndexedSlot(node, 1, Ov195_ConfigHw60C5af8ThenClearRequest); break;
        case 6: SetIndexedSlot(node, 1, Ov195_AiEnterCharge); break;
        case 7: SetIndexedSlot(node, 1, Ov195_ResetReactionAi); break;
        case 8: SetIndexedSlot(node, 1, Ov195_stateAnimPairCallback); break;
        case 9: SetIndexedSlot(node, 1, Ov195_AiEndWithUpdate); break;
        case 10: SetIndexedSlot(node, 1, Ov195_stateAimAnimEffect); break;
        case 11: SetIndexedSlot(node, 1, Ov195_stateAimAnimEffect_2); break;
        case 12: SetIndexedSlot(node, 1, Ov195_AiEnterTrackOffset); break;
        case 13: SetIndexedSlot(node, 1, Ov195_AiEnterTrackOffsetB); break;
        case 14: SetIndexedSlot(node, 1, Ov195_stateAnimEffect); break;
        case 15: SetIndexedSlot(node, 1, Ov195_AiEnterCombo); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
