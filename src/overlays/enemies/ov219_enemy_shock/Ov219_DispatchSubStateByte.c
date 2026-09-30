/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance, contact
 * and model flags and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov219_stateSetFlagsClearBit(void);
extern void Ov219_AiStep_QueueAction2(void);
extern void Ov219_AiEnterIdle(void);
extern void Ov219_BeginWander(void);
extern void Ov219_SetupGuardThenAction4(void);
extern void Ov219_Pose2ThenAimAngle(void);
extern void Ov219_BeginAttack(void);
extern void Ov219_stAdvanceState(void);
extern void Ov219_Release(void);
extern void Ov219_SetPose1ThenAdvanceSlot(void);

void Ov219_DispatchSubStateByte(int *node) {
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
            SetIndexedSlot(node, 1, Ov219_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov219_AiStep_QueueAction2);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov219_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov219_BeginWander);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov219_SetupGuardThenAction4);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov219_Pose2ThenAimAngle);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov219_BeginAttack);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov219_BeginAttack);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov219_stAdvanceState);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov219_Release);
            break;
        case 10:
            SetIndexedSlot(node, 1, Ov219_SetPose1ThenAdvanceSlot);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
