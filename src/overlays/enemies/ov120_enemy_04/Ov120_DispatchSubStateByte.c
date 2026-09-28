struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov120_stateSetFlagsClearBit(void);
extern void Ov120_SetupThenAction48(void);
extern void Ov120_AiEnterApproach(void);
extern void Ov120_SeedTimerFireAttack2ThenAdvanceSlot(void);
extern void Ov120_ComputeTargetDeltaThenAdvance(void);
extern void Ov120_ConfigSubStateThenAdvanceSlot(void);
extern void Ov120_ConfigSubStateThenAdvanceSlot_2(void);
extern void Ov120_EnterRecoveryIdle(void);
extern void Ov120_ConfigHw60FlagsBeginAction4a(void);
extern void Ov120_ConfigHw60Action49ThenAdvance(void);

void Ov120_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) == -1) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
    *(unsigned short *)(*state + 0x1ae) &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov120_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov120_SetupThenAction48);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov120_AiEnterApproach);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov120_SeedTimerFireAttack2ThenAdvanceSlot);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov120_ComputeTargetDeltaThenAdvance);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov120_ConfigSubStateThenAdvanceSlot);
        break;
    case 7:
        SetIndexedSlot(node, 1, Ov120_ConfigSubStateThenAdvanceSlot_2);
        break;
    case 8:
        SetIndexedSlot(node, 1, Ov120_EnterRecoveryIdle);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov120_ConfigHw60FlagsBeginAction4a);
        break;
    case 9:
        SetIndexedSlot(node, 1, Ov120_ConfigHw60Action49ThenAdvance);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
