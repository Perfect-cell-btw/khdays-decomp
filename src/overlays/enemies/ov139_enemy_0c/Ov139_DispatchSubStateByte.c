/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance and contact
 * and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov139_stateSetFlagsClearBit(void);
extern void Ov139_ConfigHw60Action48ThenAdvance(void);
extern void Ov139_stDiv5Store_cccac(void);
extern void Ov139_AiEnterChase(void);
extern void Ov139_stateSetFlagEffect(void);
extern void Ov139_stateSetFlagEffect_2(void);
extern void Ov139_SetPose9ThenAdvanceSlot(void);
extern void Ov139_InitRush(void);
extern void Ov139_Pose5ClearHitFlagAimAdvance(void);
extern void Ov139_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov139_ConfigHw60Action49ThenAdvance(void);

void Ov139_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov139_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov139_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov139_stDiv5Store_cccac);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov139_AiEnterChase);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov139_stateSetFlagEffect);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov139_stateSetFlagEffect_2);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov139_SetPose9ThenAdvanceSlot);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov139_InitRush);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov139_Pose5ClearHitFlagAimAdvance);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov139_ConfigHw60C5af8ThenClearRequest);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov139_ConfigHw60Action49ThenAdvance);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
