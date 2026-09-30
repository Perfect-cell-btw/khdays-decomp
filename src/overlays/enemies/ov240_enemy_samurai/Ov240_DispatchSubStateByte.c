// variant: popeq=False mirror_top=True
struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov240_stateSetFlagsClearBit(void);
extern void Ov240_RecoverEntry(void);
extern void Ov240_AiEnterIdle(void);
extern void Ov240_AiEnterWalk(void);
extern void Ov240_LungeEntry(void);
extern void Ov240_AiEnterAnim8(void);
extern void Ov240_PoseResetTimerFieldsThenAdvance(void);
extern void Ov240_AimAtTarget(void);
extern void Ov240_GuardBreakEntry(void);
extern void Ov240_BeginPushAway(void);
extern void Ov240_AiEnterWalkB(void);

void Ov240_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~3;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov240_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov240_RecoverEntry);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov240_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov240_AiEnterWalk);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov240_LungeEntry);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov240_AiEnterAnim8);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov240_PoseResetTimerFieldsThenAdvance);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov240_AimAtTarget);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov240_GuardBreakEntry);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov240_BeginPushAway);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov240_AiEnterWalkB);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
