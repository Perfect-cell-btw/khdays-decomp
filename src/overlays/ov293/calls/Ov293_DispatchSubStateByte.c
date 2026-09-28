// variant: popeq=True mirror_top=False
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov293_stateSetFlagsClearBit(void);
extern void Ov293_AiEnterAttackStance(void);
extern void Ov293_stateAnimTimer(void);
extern void Ov293_AiEnterChase(void);
extern void Ov293_ComputeTargetDeltaThenAdvance(void);
extern void Ov293_AiEnterIdle(void);
extern void Ov293_SetVisFlagPose7PlayAdvance(void);
extern void Ov293_ConfigHw60FlagsBeginAction4a(void);

void Ov293_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) == -1) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov293_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov293_AiEnterAttackStance);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov293_stateAnimTimer);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov293_AiEnterChase);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov293_ComputeTargetDeltaThenAdvance);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov293_AiEnterIdle);
        break;
    case 7:
        SetIndexedSlot(node, 1, Ov293_SetVisFlagPose7PlayAdvance);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov293_ConfigHw60FlagsBeginAction4a);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
