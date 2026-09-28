/* Sub-state dispatcher of the ov291 enemy. With no pending +0x1c7 request and outside
 * sub-states 0/6 the target is refreshed: the state's +0x2c override or, failing that, the
 * closest player found by cc670. A target whose +0x1b4 kind has flag bit 16 set is handed to the
 * actor's +0x3a8 target hook; otherwise its +0x18c item is activated (ad838) and sub-state 6 is
 * requested. A pending request then becomes the +0x1c6 sub-state: bits 1/2/3/7 of the +0x60 high
 * byte clear, slot 1 takes the sub-state's entry (ccc18, cccd0 for 1 -> 2 and 2, ccd28, cd430,
 * cd498, cd524, cd578) and the request is cleared. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct SubState { signed char pad[0x1c6]; signed char nSub1c6; signed char nNext1c7; };

extern int Ov291_FindTarget(int self);
extern long long *GetEntryField20ByIndex(int kind);
extern void Ov291_stSetDispFlags86(void);
extern void Ov291_SetPose0ThenAdvanceSlot(void);
extern void Ov291_ConfigSubStateThenAdvanceSlot(void);
extern void Ov291_SetPose4ThenAdvanceSlot(void);
extern void Ov291_SetPose5ThenAdvanceSlot(void);
extern void Ov291_AiFinishAndNotifyOwner(void);
extern void Ov291_SetPose7ThenAdvanceSlot(void);
extern void func_ov022_020ad838(int item, int on);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov291_SubStateDispatch(int *node)
{
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x1c7) == -1 &&
        *(signed char *)(*state + 0x1c6) != 0 && *(signed char *)(*state + 0x1c6) != 6) {
        if (state[0xb] != 0) {
            *(int *)(*state + 0x3ac) = state[0xb];
        } else {
            *(int *)(*state + 0x3ac) = Ov291_FindTarget(*state);
        }
        if (*(int *)(*state + 0x3ac) != 0) {
            if ((*GetEntryField20ByIndex(*(unsigned char *)(*(int *)(*state + 0x3ac) + 0x1b4)) & 0x10000) != 0) {
                /* the hook takes the target kind and the actor (r1 keeps the actor live) */
                if (*(void (**)(int, int))(*state + 0x3a8) != 0) {
                    (*(void (**)(int, int))(*state + 0x3a8))(*(unsigned char *)(*(int *)(*state + 0x3ac) + 0x1b4), *state);
                }
            } else {
                func_ov022_020ad838(*(int *)(*(int *)(*state + 0x3ac) + 0x18c), 1);
                *(unsigned char *)(*state + 0x1c7) = 6;
            }
        }
    }
    if (*(signed char *)(*state + 0x1c7) != -1) {
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x8e;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov291_stSetDispFlags86);
            break;
        case 1:
            ((struct SubState *)*state)->nSub1c6 = 2;
            /* fallthrough */
        case 2:
            SetIndexedSlot(node, 1, Ov291_SetPose0ThenAdvanceSlot);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov291_ConfigSubStateThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov291_SetPose4ThenAdvanceSlot);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov291_SetPose5ThenAdvanceSlot);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov291_AiFinishAndNotifyOwner);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov291_SetPose7ThenAdvanceSlot);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
