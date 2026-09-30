/* AI dispatcher: when an action is pending, makes it current, resets the actor's contact, model and
 * stance flags and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov292_stateSetFlagsClearBit(void);
extern void Ov292_ConfigHw60Action48ThenAdvance(void);
extern void Ov292_stAdvanceState(void);
extern void Ov292_ConfigSubStateThenAdvanceSlot(void);
extern void Ov292_ConfigSubStateThenAdvanceSlot_2(void);
extern void Ov292_ConfigSubStateThenAdvanceSlot_3(void);
extern void Ov292_Action49Callback(void);
extern void Ov292_ExitChase(void);

void Ov292_DispatchSubStateByte(int *node) {
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
            SetIndexedSlot(node, 1, Ov292_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov292_ConfigHw60Action48ThenAdvance);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov292_stAdvanceState);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov292_ConfigSubStateThenAdvanceSlot);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov292_ConfigSubStateThenAdvanceSlot_2);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov292_ConfigSubStateThenAdvanceSlot_3);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov292_Action49Callback);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov292_ExitChase);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
