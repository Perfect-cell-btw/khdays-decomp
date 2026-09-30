/* Sub-state dispatcher of the ov243 enemy. With no pending +0x1c7 request and outside
 * sub-state 6 the +0x30 target is refreshed by the target finder (020d3d78). A target whose
 * +0x1b4 kind has flag bit 16 set is handed to the actor's +0x3ac target hook; otherwise its
 * +0x18c item is activated (ad838) and sub-state 6 is requested. A pending request then becomes
 * the +0x1c6 sub-state: bits 1/2/3/6/7 of the +0x60 high byte and bit 0 of +0x1ae clear, slot 1
 * takes the sub-state's entry (020d4208, 020d429c, 020d42c0, 020d44b4; 4/5 keep it; 6: 020d46cc)
 * and the request is cleared. */
struct hw60 { unsigned short lo : 8, hi : 8; };

extern int Ov243_FindTarget(int *node);
extern long long *GetEntryField20ByIndex(int kind);
extern void Ov243_stSetDispFlags86(void);
extern void Ov243_stAdvanceState(void);
extern void Ov243_ArriveWaypoint(void);
extern void Ov243_ConfigSubStateThenAdvanceSlot_3(void);
extern void Ov243_ConfigSubStateThenAdvanceSlot_4(void);
extern void func_ov022_020ad838(int item, int on);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov243_SubStateDispatch(int *node)
{
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x1c7) == -1 && *(signed char *)(*state + 0x1c6) != 6) {
        state[0xc] = Ov243_FindTarget(node);
        if (state[0xc] != 0) {
            if ((*GetEntryField20ByIndex(*(unsigned char *)(state[0xc] + 0x1b4)) & 0x10000) != 0) {
                /* the hook takes the target kind and the actor (r1 keeps the actor live) */
                if (*(void (**)(int, int))(*state + 0x3ac) != 0) {
                    (*(void (**)(int, int))(*state + 0x3ac))(*(unsigned char *)(state[0xc] + 0x1b4), *state);
                }
            } else {
                func_ov022_020ad838(*(int *)(state[0xc] + 0x18c), 1);
                *(unsigned char *)(*state + 0x1c7) = 6;
            }
        }
    }
    if (*(signed char *)(*state + 0x1c7) != -1) {
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xce;
        *(unsigned short *)(*state + 0x1ae) &= ~1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov243_stSetDispFlags86);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov243_stAdvanceState);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov243_ArriveWaypoint);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov243_ConfigSubStateThenAdvanceSlot_3);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov243_ConfigSubStateThenAdvanceSlot_4);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
