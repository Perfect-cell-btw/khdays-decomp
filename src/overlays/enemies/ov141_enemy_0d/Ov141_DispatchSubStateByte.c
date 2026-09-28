// variant: popeq=True mirror_top=False
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov141_stateSetFlagsClearBit(void);
extern void Ov141_stSetFlagsEffectClear82(void);
extern void Ov141_stateTimerRandomRange(void);
extern void Ov141_PickApproachHeading(void);
extern void Ov141_ProjectileAction_Enter(void);
extern void Ov141_FaceTarget(void);
extern void Ov141_stAimAngleToTarget(void);
extern void Ov141_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov141_stClearFlag1SetFlags86(void);

void Ov141_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) == -1) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
    *(unsigned short *)(*state + 0x1ae) &= ~0x41;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov141_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov141_stSetFlagsEffectClear82);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov141_stateTimerRandomRange);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov141_PickApproachHeading);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov141_ProjectileAction_Enter);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov141_FaceTarget);
        break;
    case 7:
        SetIndexedSlot(node, 1, Ov141_stAimAngleToTarget);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov141_ConfigHw60C5af8ThenClearRequest);
        break;
    case 8:
        SetIndexedSlot(node, 1, Ov141_stClearFlag1SetFlags86);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
