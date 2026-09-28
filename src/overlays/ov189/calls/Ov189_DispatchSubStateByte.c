struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov189_stateSetFlagsClearBit(void);
extern void Ov189_ConfigHw60Action48ThenAdvance(void);
extern void Ov189_PickNextWaitTime(void);
extern void Ov189_PickWaitAndResetCounter(void);
extern void Ov189_ComputeTargetDeltaThenAdvance(void);
extern void Ov189_ConfigSubStateThenAdvanceSlot(void);
extern void Ov189_ConfigSubStateThenAdvanceSlot_2(void);
extern void Ov189_EnterWindDown(void);
extern void Ov189_PlayCueAtOrigin(void);
extern void Ov189_ConfigHw60FlagsBeginAction4b(void);
extern void Ov189_BeginChargeStance(void);
extern void Ov189_SetPose2ThenAdvanceSlot(void);

void Ov189_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov189_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov189_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov189_PickNextWaitTime);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov189_PickWaitAndResetCounter);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov189_ComputeTargetDeltaThenAdvance);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov189_ConfigSubStateThenAdvanceSlot);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov189_ConfigSubStateThenAdvanceSlot_2);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov189_EnterWindDown);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov189_PlayCueAtOrigin);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov189_ConfigHw60FlagsBeginAction4b);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov189_BeginChargeStance);
            break;
        case 0xb:
            SetIndexedSlot(node, 1, Ov189_SetPose2ThenAdvanceSlot);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
