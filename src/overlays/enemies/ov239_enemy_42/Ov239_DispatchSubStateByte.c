// variant: popeq=False mirror_top=True
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov239_stateSetFlagsClearBit(void);
extern void Ov239_RecoverEntry(void);
extern void Ov239_AiEnterIdle(void);
extern void Ov239_WanderEntry(void);
extern void Ov239_AiEnterAnim8(void);
extern void Ov239_AttackEntry(void);
extern void Ov239_BeginAimAtTarget(void);
extern void Ov239_GuardBreakEntry(void);
extern void Ov239_BeginPushAway(void);
extern void Ov239_BeginSubActionWithCallback(void);

void Ov239_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov239_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov239_RecoverEntry);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov239_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov239_WanderEntry);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov239_AiEnterAnim8);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov239_AttackEntry);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov239_BeginAimAtTarget);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov239_GuardBreakEntry);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov239_BeginPushAway);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov239_BeginSubActionWithCallback);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
