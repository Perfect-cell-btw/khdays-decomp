/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6), resets the
 * per-action flags and installs the step that starts that action; then marks nothing pending. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov196_stSetFlags86Clear(void);
extern void Ov196_stSetFlags82ClearC(void);
extern void Ov196_stDiv15Store(void);
extern void Ov196_stateAnimAimAtTarget(void);
extern void Ov196_stDivPoseEffect(void);
extern void Ov196_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov196_AiEnterCharge(void);
extern void Ov196_ResetReactionAi(void);
extern void Ov196_stateAnimPairCallback(void);
extern void Ov196_AiEndWithUpdate(void);
extern void Ov196_stateAimAnimEffect(void);
extern void Ov196_stateAimAnimEffect_2(void);
extern void Ov196_AiEnterTrackOffset(void);
extern void Ov196_AiEnterTrackOffsetB(void);
extern void Ov196_stateAnimEffect(void);
extern void Ov196_AiEnterCombo(void);

void Ov196_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov196_stSetFlags86Clear); break;
        case 1: SetIndexedSlot(node, 1, Ov196_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov196_stDiv15Store); break;
        case 5: SetIndexedSlot(node, 1, Ov196_stateAnimAimAtTarget); break;
        case 4: SetIndexedSlot(node, 1, Ov196_stDivPoseEffect); break;
        case 3: SetIndexedSlot(node, 1, Ov196_ConfigHw60C5af8ThenClearRequest); break;
        case 6: SetIndexedSlot(node, 1, Ov196_AiEnterCharge); break;
        case 7: SetIndexedSlot(node, 1, Ov196_ResetReactionAi); break;
        case 8: SetIndexedSlot(node, 1, Ov196_stateAnimPairCallback); break;
        case 9: SetIndexedSlot(node, 1, Ov196_AiEndWithUpdate); break;
        case 10: SetIndexedSlot(node, 1, Ov196_stateAimAnimEffect); break;
        case 11: SetIndexedSlot(node, 1, Ov196_stateAimAnimEffect_2); break;
        case 12: SetIndexedSlot(node, 1, Ov196_AiEnterTrackOffset); break;
        case 13: SetIndexedSlot(node, 1, Ov196_AiEnterTrackOffsetB); break;
        case 14: SetIndexedSlot(node, 1, Ov196_stateAnimEffect); break;
        case 15: SetIndexedSlot(node, 1, Ov196_AiEnterCombo); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
