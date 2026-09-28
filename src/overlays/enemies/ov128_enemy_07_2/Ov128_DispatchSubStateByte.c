/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6), resets the
 * per-action flags (the high byte of +0x60, +0x1ae, the model's flag byte) and installs the step
 * that starts that action; then marks nothing pending. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov128_stateSetFlagsClearBit(void);
extern void Ov128_ConfigHw60Action48ThenAdvance(void);
extern void Ov128_SetPose1ThenAdvanceSlot(void);
extern void Ov128_AiEnterChase(void);
extern void Ov128_SetHw60Flag40ThenAdvance(void);
extern void Ov128_SetPose3ThenAdvanceSlot(void);
extern void Ov128_SetFlagsAndAdvance(void);
extern void Ov128_ConfigHw60ActionCallSubThenAdvance(void);
extern void Ov128_BeginWindUp(void);

void Ov128_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov128_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov128_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov128_SetPose1ThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov128_AiEnterChase);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov128_SetHw60Flag40ThenAdvance);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov128_SetPose3ThenAdvanceSlot);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov128_SetFlagsAndAdvance);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov128_ConfigHw60ActionCallSubThenAdvance);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov128_BeginWindUp);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
