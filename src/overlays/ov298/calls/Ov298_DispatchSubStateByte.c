// variant: popeq=False mirror_top=True
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov298_stateSetFlagsClearBit(void);
extern void Ov298_ConfigSubStateThenAdvanceSlot(void);
extern void Ov298_Pose1SetupWithTimerThenAdvance(void);
extern void Ov298_LeapEntry(void);
extern void Ov298_ApproachEntry(void);
extern void Ov298_TurnEntry(void);
extern void Ov298_RetreatEntry(void);
extern void Ov298_AiWarpToArenaSpot(void);
extern void Ov298_ConfigSubStateThenAdvanceSlot_2(void);

void Ov298_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov298_stateSetFlagsClearBit);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov298_ConfigSubStateThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov298_Pose1SetupWithTimerThenAdvance);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov298_LeapEntry);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov298_ApproachEntry);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov298_TurnEntry);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov298_RetreatEntry);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov298_AiWarpToArenaSpot);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov298_ConfigSubStateThenAdvanceSlot_2);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
