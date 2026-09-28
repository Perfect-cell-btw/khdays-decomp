/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance, contact
 * and model flags and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov276_stSetFlags86Clear3ac(void);
extern void Ov276_SetChargeFlagsAndDispatch(void);
extern void Ov276_AiEnterIdle(void);
extern void Ov276_RerollTimerThenDispatchSlot5c(void);
extern void Ov276_GrabRelease(void);
extern void Ov276_PushOffsetTwiceAndReset(void);
extern void Ov276_stateFixedAngleMatrix_4(void);
extern void Ov276_DescentEntry(void);
extern void Ov276_AscentEntry(void);
extern void Ov276_AiEnterApproach(void);

void Ov276_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~0x3;
        ((struct bf *)(*(int *)(*state + 0x3ac) + 8))->b |= 1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov276_stSetFlags86Clear3ac);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov276_SetChargeFlagsAndDispatch);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov276_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov276_RerollTimerThenDispatchSlot5c);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov276_GrabRelease);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov276_PushOffsetTwiceAndReset);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov276_stateFixedAngleMatrix_4);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov276_DescentEntry);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov276_AscentEntry);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov276_AiEnterApproach);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
