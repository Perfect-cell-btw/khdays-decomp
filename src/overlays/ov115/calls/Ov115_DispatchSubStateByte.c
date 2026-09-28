struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov115_stateSetFlagsClearBit(void);
extern void Ov115_stateSetFlagsInitAnim(void);
extern void Ov115_stateRandomInitFull(void);
extern void Ov115_AiStep_StartTag1WithTimer(void);
extern void Ov115_AiStep_StartTag1(void);
extern void Ov115_stateRandomDirValue(void);
extern void Ov115_EngageEnter(void);
extern void Ov115_BeginGuardPose(void);
extern void Ov115_SetPose3ThenAdvanceSlot(void);
extern void Ov115_SetPose4ThenAdvanceSlot(void);
extern void Ov115_stateSetFlagsEffectClear(void);
extern void Ov115_AiEndWithUpdate(void);

void Ov115_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        {
            unsigned short *p = (unsigned short *)(*state + 0x60);
            unsigned int u = *p;
            *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
        }
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x8e;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov115_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov115_stateSetFlagsInitAnim);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov115_stateRandomInitFull);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov115_AiStep_StartTag1WithTimer);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov115_AiStep_StartTag1);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov115_stateRandomDirValue);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov115_EngageEnter);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov115_BeginGuardPose);
            break;
        case 0xc:
            SetIndexedSlot(node, 1, Ov115_SetPose3ThenAdvanceSlot);
            break;
        case 0xd:
            SetIndexedSlot(node, 1, Ov115_SetPose4ThenAdvanceSlot);
            break;
        case 0xe:
            SetIndexedSlot(node, 1, Ov115_stateSetFlagsEffectClear);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov115_AiEndWithUpdate);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
