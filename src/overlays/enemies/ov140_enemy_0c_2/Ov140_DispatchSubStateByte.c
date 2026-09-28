/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance and contact
 * and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov140_stateSetFlagsClearBit(void);
extern void Ov140_ConfigHw60Action48ThenAdvance(void);
extern void Ov140_stDiv5Store(void);
extern void Ov140_AiEnterChase(void);
extern void Ov140_stateSetFlagEffect(void);
extern void Ov140_stateSetFlagEffect_2(void);
extern void Ov140_SetPose9ThenAdvanceSlot(void);
extern void Ov140_InitRush(void);
extern void Ov140_Pose5ClearHitFlagAimAdvance(void);
extern void Ov140_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov140_ConfigHw60Action49ThenAdvance(void);

void Ov140_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov140_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov140_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov140_stDiv5Store);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov140_AiEnterChase);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov140_stateSetFlagEffect);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov140_stateSetFlagEffect_2);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov140_SetPose9ThenAdvanceSlot);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov140_InitRush);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov140_Pose5ClearHitFlagAimAdvance);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov140_ConfigHw60C5af8ThenClearRequest);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov140_ConfigHw60Action49ThenAdvance);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
