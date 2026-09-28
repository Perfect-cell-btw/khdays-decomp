/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance and contact
 * and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov194_stSetFlags86Clear(void);
extern void Ov194_stSetFlags82ClearC(void);
extern void Ov194_stDiv15Store_ccecc(void);
extern void Ov194_stateAnimAimAtTarget(void);
extern void Ov194_stDivPoseEffect(void);
extern void Ov194_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov194_AiEnterCharge(void);
extern void Ov194_ResetReactionAi(void);
extern void Ov194_stateAnimPairCallback(void);
extern void Ov194_AiEndWithUpdate(void);
extern void Ov194_stateAimAnimEffect(void);
extern void Ov194_stateAimAnimEffect_2(void);
extern void Ov194_AiEnterTrackOffset(void);
extern void Ov194_AiEnterTrackOffsetB(void);
extern void Ov194_stateAnimEffect(void);
extern void Ov194_AiEnterCombo(void);

void Ov194_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov194_stSetFlags86Clear); break;
        case 1: SetIndexedSlot(node, 1, Ov194_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov194_stDiv15Store_ccecc); break;
        case 5: SetIndexedSlot(node, 1, Ov194_stateAnimAimAtTarget); break;
        case 4: SetIndexedSlot(node, 1, Ov194_stDivPoseEffect); break;
        case 3: SetIndexedSlot(node, 1, Ov194_ConfigHw60C5af8ThenClearRequest); break;
        case 6: SetIndexedSlot(node, 1, Ov194_AiEnterCharge); break;
        case 7: SetIndexedSlot(node, 1, Ov194_ResetReactionAi); break;
        case 8: SetIndexedSlot(node, 1, Ov194_stateAnimPairCallback); break;
        case 9: SetIndexedSlot(node, 1, Ov194_AiEndWithUpdate); break;
        case 10: SetIndexedSlot(node, 1, Ov194_stateAimAnimEffect); break;
        case 11: SetIndexedSlot(node, 1, Ov194_stateAimAnimEffect_2); break;
        case 12: SetIndexedSlot(node, 1, Ov194_AiEnterTrackOffset); break;
        case 13: SetIndexedSlot(node, 1, Ov194_AiEnterTrackOffsetB); break;
        case 14: SetIndexedSlot(node, 1, Ov194_stateAnimEffect); break;
        case 15: SetIndexedSlot(node, 1, Ov194_AiEnterCombo); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
