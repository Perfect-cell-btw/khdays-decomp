struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov287_SetHw60Bit15ClearSubBit0ThenAdvanceSlot(void);
extern void Ov287_AiEnterHold(void);
extern void Ov287_StageVecsResetFieldsThenAdvanceSlot(void);
extern void Ov287_SetupActionVariantThenAdvanceSlot(void);
extern void Ov287_ResetHw60FlagsAndTimer34ThenAdvance(void);

void Ov287_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c == -1) return;
    *(signed char *)(*state + 0x1c6) = (signed char)c;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x80;
    *(unsigned short *)(*state + 0x1ae) &= ~0x13;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov287_SetHw60Bit15ClearSubBit0ThenAdvanceSlot);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov287_AiEnterHold);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov287_StageVecsResetFieldsThenAdvanceSlot);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov287_SetupActionVariantThenAdvanceSlot);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov287_ResetHw60FlagsAndTimer34ThenAdvance);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
