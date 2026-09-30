// variant: popeq=False mirror_top=True
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov152_stateSetFlagsClearBit(void);
extern void Ov152_Action48Callback(void);
extern void Ov152_stateTimerRandomRange(void);
extern void Ov152_AiEnterApproachArc(void);
extern void Ov152_ProjectileAction_Enter(void);
extern void Ov152_BeginAimAtTarget(void);
extern void Ov152_Pose3AimYawAdvance(void);
extern void Ov152_ConfigHw60FlagsBeginAction4a(void);
extern void Ov152_stateToggleFlagsEffectClear(void);

void Ov152_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~0x41;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov152_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov152_Action48Callback);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov152_stateTimerRandomRange);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov152_AiEnterApproachArc);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov152_ProjectileAction_Enter);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov152_BeginAimAtTarget);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov152_Pose3AimYawAdvance);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov152_ConfigHw60FlagsBeginAction4a);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov152_stateToggleFlagsEffectClear);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
