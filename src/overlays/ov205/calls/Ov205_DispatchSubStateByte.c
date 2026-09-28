struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov205_stateSetFlagsClearBit(void);
extern void Ov205_ConfigHw60Action48ThenAdvance(void);
extern void Ov205_stDiv5Store(void);
extern void Ov205_AiEnterChase(void);
extern void Ov205_BeginPose5Aim(void);
extern void Ov205_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov205_AiEnterAnim6WithSpeed(void);
extern void Ov205_stateSetFlagEffect(void);
extern void Ov205_SetPose9ThenAdvanceSlot(void);
extern void Ov205_EnterBounce(void);
extern void Ov205_ConfigHw60Action49ThenAdvance(void);
extern void Ov205_AiEnterAnim13(void);

void Ov205_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov205_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov205_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov205_stDiv5Store);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov205_AiEnterChase);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov205_BeginPose5Aim);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov205_ConfigHw60C5af8ThenClearRequest);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov205_AiEnterAnim6WithSpeed);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov205_stateSetFlagEffect);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov205_SetPose9ThenAdvanceSlot);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov205_EnterBounce);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov205_ConfigHw60Action49ThenAdvance);
            break;
        case 0xb:
            SetIndexedSlot(node, 1, Ov205_AiEnterAnim13);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
