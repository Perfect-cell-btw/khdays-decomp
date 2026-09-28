// variant: popeq=True mirror_top=False
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov123_stateSetFlagsClearBit(void);
extern void Ov123_Action48Callback(void);
extern void Ov123_AiEnterAnim1WithTimer(void);
extern void Ov123_ResetAndInvokeMethodThenAdvance(void);
extern void Ov123_SetPose2ThenAdvanceSlot(void);
extern void Ov123_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov123_ConfigHw60Action49ThenAdvance(void);

void Ov123_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) == -1) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov123_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov123_Action48Callback);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov123_AiEnterAnim1WithTimer);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov123_ResetAndInvokeMethodThenAdvance);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov123_SetPose2ThenAdvanceSlot);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov123_ConfigHw60C5af8ThenClearRequest);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov123_ConfigHw60Action49ThenAdvance);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
