/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6), resets the
 * per-action flags and installs the step that starts that action; then marks nothing pending. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov173_stateSetFlagsClearBit(void);
extern void Ov173_stateSetFlagsInitAnim(void);
extern void Ov173_BeginWander(void);
extern void Ov173_SetPoseAndRandomTimer(void);
extern void Ov173_AiStep_StartTag1(void);
extern void Ov173_stateRandomDirValue(void);
extern void Ov173_QueryTargetThenAdvance(void);
extern void Ov173_BeginDash(void);
extern void Ov173_ConfigAimVecThenAction8(void);
extern void Ov173_FlightStep1(void);
extern void Ov173_BeginGuardPose(void);
extern void Ov173_SetPose3ThenAdvanceSlot(void);
extern void Ov173_SetPose4ThenAdvanceSlot(void);
extern void Ov173_stateSetFlagsEffectClear(void);
extern void Ov173_AiEndWithUpdate(void);

void Ov173_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        *(unsigned short *)(*state + 0x1ae) &= ~0x1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
          *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x8e;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov173_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov173_stateSetFlagsInitAnim);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov173_BeginWander);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov173_SetPoseAndRandomTimer);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov173_AiStep_StartTag1);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov173_stateRandomDirValue);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov173_QueryTargetThenAdvance);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov173_BeginDash);
            break;
        case 0xa:
            SetIndexedSlot(node, 1, Ov173_ConfigAimVecThenAction8);
            break;
        case 0xb:
            SetIndexedSlot(node, 1, Ov173_FlightStep1);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov173_BeginGuardPose);
            break;
        case 0xc:
            SetIndexedSlot(node, 1, Ov173_SetPose3ThenAdvanceSlot);
            break;
        case 0xd:
            SetIndexedSlot(node, 1, Ov173_SetPose4ThenAdvanceSlot);
            break;
        case 0xe:
            SetIndexedSlot(node, 1, Ov173_stateSetFlagsEffectClear);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov173_AiEndWithUpdate);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
