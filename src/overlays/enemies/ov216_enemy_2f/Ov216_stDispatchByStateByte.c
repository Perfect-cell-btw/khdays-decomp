/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6), resets the
 * per-action flags and installs the step that starts that action; then marks nothing pending. */

struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov216_stSetFlags86Clear3ac(void);
extern void Ov216_stSetFlags82ClearC(void);
extern void Ov216_AiEnterAim(void);
extern void Ov216_stEnterRandDelay(void);
extern void Ov216_EnterAdvancePhase(void);
extern void Ov216_ComputeAimAngleThenAction6(void);
extern void Ov216_stSetFlags86Effect4d(void);
extern void Ov216_EnterGroundedState(void);
extern void Ov216_SetPose2ThenAdvanceSlot(void);

void Ov216_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) != -1) {
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x3ac) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov216_stSetFlags86Clear3ac); break;
        case 1: SetIndexedSlot(node, 1, Ov216_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov216_AiEnterAim); break;
        case 4: SetIndexedSlot(node, 1, Ov216_stEnterRandDelay); break;
        case 5: SetIndexedSlot(node, 1, Ov216_EnterAdvancePhase); break;
        case 6: SetIndexedSlot(node, 1, Ov216_ComputeAimAngleThenAction6); break;
        case 3: SetIndexedSlot(node, 1, Ov216_stSetFlags86Effect4d); break;
        case 7: SetIndexedSlot(node, 1, Ov216_EnterGroundedState); break;
        case 8: SetIndexedSlot(node, 1, Ov216_SetPose2ThenAdvanceSlot); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
