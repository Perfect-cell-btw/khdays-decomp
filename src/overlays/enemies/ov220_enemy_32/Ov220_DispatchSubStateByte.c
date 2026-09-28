struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov220_stateSetFlagsClearBit(void);
extern void Ov220_AiStep_QueueAction2(void);
extern void Ov220_AiEnterIdle(void);
extern void Ov220_BeginWander(void);
extern void Ov220_SetupGuardThenAction4(void);
extern void Ov220_AiEnterAnim5(void);
extern void Ov220_SetupGuardThenPose6(void);
extern void Ov220_Pose2ThenAimAngle(void);
extern void Ov220_Action6ThenAimAngle(void);
extern void Ov220_Action6AfterSubDispatch(void);
extern void Ov220_stAdvanceState(void);
extern void Ov220_Release(void);
extern void Ov220_SetPose1ThenAdvanceSlot(void);

void Ov220_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~0x3;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 0x1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~0x2;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov220_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov220_AiStep_QueueAction2);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov220_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov220_BeginWander);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov220_SetupGuardThenAction4);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov220_AiEnterAnim5);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov220_SetupGuardThenPose6);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov220_Pose2ThenAimAngle);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov220_Action6ThenAimAngle);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov220_Action6AfterSubDispatch);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov220_stAdvanceState);
            break;
        case 0xb:
            SetIndexedSlot(node, 1, Ov220_Release);
            break;
        case 0xc:
            SetIndexedSlot(node, 1, Ov220_SetPose1ThenAdvanceSlot);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
