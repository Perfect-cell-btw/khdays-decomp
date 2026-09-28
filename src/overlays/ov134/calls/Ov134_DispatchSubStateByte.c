struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov134_SetVisFlagsClearLowAdvance(void);
extern void Ov134_Action48Callback(void);
extern void Ov134_stateTimerRandomRange(void);
extern void Ov134_ComputeTargetDeltaThenAdvance(void);
extern void Ov134_stDivPoseEffect(void);
extern void Ov134_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov134_AiEnterBurst(void);
extern void Ov134_AiEnterSubState(void);
extern void Ov134_stateAnimPairCallback(void);
extern void Ov134_ConfigHw60Action49ThenAdvance(void);

void Ov134_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) != -1) {
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov134_SetVisFlagsClearLowAdvance);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov134_Action48Callback);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov134_stateTimerRandomRange);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov134_ComputeTargetDeltaThenAdvance);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov134_stDivPoseEffect);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov134_ConfigHw60C5af8ThenClearRequest);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov134_AiEnterBurst);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov134_AiEnterSubState);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov134_stateAnimPairCallback);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov134_ConfigHw60Action49ThenAdvance);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
