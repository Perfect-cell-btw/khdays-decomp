/* AI dispatcher: when an action is pending, resets the actor's stance, contact and model flags,
 * makes it current and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov286_stateSetFlagsClearBit(void);
extern void Ov286_Action48Callback(void);
extern void Ov286_stDiv5Store(void);
extern void Ov286_Chase_Enter(void);
extern void Ov286_ConfigHw60FlagsBeginAction4a(void);
extern void Ov286_ConfigHw60BeginAction49(void);

void Ov286_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 1;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov286_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov286_Action48Callback);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov286_stDiv5Store);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov286_Chase_Enter);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov286_ConfigHw60FlagsBeginAction4a);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov286_ConfigHw60BeginAction49);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
