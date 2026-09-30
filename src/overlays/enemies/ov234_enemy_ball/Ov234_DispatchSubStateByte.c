/* AI dispatcher: when an action is pending, makes it current, resets the actor's stance and model
 * flags and installs its step handler. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov234_stAdvanceState_ccedc(void);
extern void Ov234_stAdvanceState(void);
extern void Ov234_stAdvanceState_2(void);
extern void Ov234_AiStep_SetFlags3AndEnd(void);

void Ov234_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 1;
        { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
          *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov234_stAdvanceState_ccedc);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov234_stAdvanceState);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov234_stAdvanceState_2);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov234_AiStep_SetFlags3AndEnd);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
