// variant: popeq=False mirror_top=True
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov203_stateSetFlagsClearBit(void);
extern void Ov203_ConfigHw60Action48ThenAdvance(void);
extern void Ov203_stDiv30Store(void);
extern void Ov203_stDiv30Store_2(void);
extern void Ov203_AiEnterAim(void);
extern void Ov203_ComputeTargetDeltaThenAdvance(void);
extern void Ov203_stateSetFlagEffect(void);
extern void Ov203_SetPose6ThenAdvanceSlot(void);
extern void Ov203_BeginThrowRelease(void);
extern void Ov203_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov203_AiEndWithUpdate(void);

void Ov203_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov203_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov203_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov203_stDiv30Store);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov203_stDiv30Store_2);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov203_AiEnterAim);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov203_ComputeTargetDeltaThenAdvance);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov203_stateSetFlagEffect);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov203_SetPose6ThenAdvanceSlot);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov203_BeginThrowRelease);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov203_ConfigHw60C5af8ThenClearRequest);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov203_AiEndWithUpdate);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
