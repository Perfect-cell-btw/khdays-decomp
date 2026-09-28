struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov217_stSetFlags86Clear3ac(void);
extern void Ov217_stSetFlags82ClearC(void);
extern void Ov217_AiEnterAim(void);
extern void Ov217_stEnterRandDelay(void);
extern void Ov217_EnterAdvancePhase(void);
extern void Ov217_ComputeAimAngleThenAction6(void);
extern void Ov217_stSetFlags86Effect4d(void);
extern void Ov217_EnterGroundedState(void);
extern void Ov217_SetPose2ThenAdvanceSlot(void);

void Ov217_stDispatchByStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) != -1) {
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x3ac) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0: SetIndexedSlot(node, 1, Ov217_stSetFlags86Clear3ac); break;
        case 1: SetIndexedSlot(node, 1, Ov217_stSetFlags82ClearC); break;
        case 2: SetIndexedSlot(node, 1, Ov217_AiEnterAim); break;
        case 4: SetIndexedSlot(node, 1, Ov217_stEnterRandDelay); break;
        case 5: SetIndexedSlot(node, 1, Ov217_EnterAdvancePhase); break;
        case 6: SetIndexedSlot(node, 1, Ov217_ComputeAimAngleThenAction6); break;
        case 3: SetIndexedSlot(node, 1, Ov217_stSetFlags86Effect4d); break;
        case 7: SetIndexedSlot(node, 1, Ov217_EnterGroundedState); break;
        case 8: SetIndexedSlot(node, 1, Ov217_SetPose2ThenAdvanceSlot); break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
