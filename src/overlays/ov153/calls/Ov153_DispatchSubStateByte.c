struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov153_stateSetFlagsClearBit(void);
extern void Ov153_ConfigHw60Action48ThenAdvance(void);
extern void Ov153_AiEnterStalk(void);
extern void Ov153_SetPose2ThenAdvanceSlot(void);
extern void Ov153_ConfigHw60C5af8ThenClearRequest(void);
extern void Ov153_ConfigHw60Action49ThenAdvance(void);
extern void Ov153_stateAnimFlagCallback(void);

void Ov153_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c7) == -1) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
    *(unsigned short *)(*state + 0x1ae) &= ~0x41;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov153_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov153_ConfigHw60Action48ThenAdvance);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov153_AiEnterStalk);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov153_SetPose2ThenAdvanceSlot);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov153_ConfigHw60C5af8ThenClearRequest);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov153_ConfigHw60Action49ThenAdvance);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov153_stateAnimFlagCallback);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
