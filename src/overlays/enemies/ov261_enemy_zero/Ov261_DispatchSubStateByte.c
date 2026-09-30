/* State dispatcher: when an action is pending (+0x1c7 not -1) sets the per-action flags, makes it
 * current (+0x1c6) and installs the step that starts that action; then marks nothing pending. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov261_SetPoseClearField3a8ThenAdvanceSlot(void);
extern void Ov261_ConfigSubStateThenAdvanceSlot(void);
extern void Ov261_ApproachDecision(void);
extern void Ov261_PoseInvokeClearField40ThenAdvance(void);

void Ov261_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c == -1) return;
    { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
      *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x44) << 0x18) >> 0x10)); }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x8;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
    switch (*(signed char *)(*state + 0x1c6)) {
    case 2:
        SetIndexedSlot(node, 1, Ov261_SetPoseClearField3a8ThenAdvanceSlot);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov261_ConfigSubStateThenAdvanceSlot);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov261_ApproachDecision);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov261_PoseInvokeClearField40ThenAdvance);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
