/* State dispatcher: first turns a hurt flag into the hit action (5), or into defeat (3) when the
 * hit points are gone; then, when an action is pending, makes it current, resets the per-action
 * flags and installs the step that starts it. */

struct bf { unsigned b : 8; };
struct st1c7 { signed char _pad[0x1c7]; signed char sub; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov191_stSetFlagsC6ClearBits(void);
extern void Ov191_stSetFlags82ClearC(void);
extern void Ov191_SetPose1ThenAdvanceSlot(void);
extern void Ov191_BeginPickTarget(void);
extern void Ov191_SetPose2ThenAdvanceSlot(void);
extern void Ov191_stClearFlag1SetFlags86C(void);
extern void Ov191_stClearFlag1SetFlags86B(void);
extern void Ov191_Pose4ClearFieldsAdvance(void);

void Ov191_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(*state + 0x1c4) & 2) {
        if (*(short *)(*state + 0x21a) > 0 &&
            *(signed char *)(*state + 0x1c6) != 3 &&
            *(signed char *)(*state + 0x1c8) != 3 &&
            *(signed char *)(*state + 0x1c7) != 3) {
            ((struct st1c7 *)*state)->sub = 5;
        } else {
            *(unsigned char *)(*state + 0x1c4) ^= 2;
            *(signed char *)(*state + 0x1c7) = 3;
        }
    }
    int c = *(signed char *)(*state + 0x1c7);
    if (c == -1) return;
        *(signed char *)(*state + 0x1c6) = (signed char)c;
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(*state + 0x1ae) &= ~0x1;
        ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b |= 0x1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b |= 0x1;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov191_stSetFlagsC6ClearBits);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov191_stSetFlags82ClearC);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov191_SetPose1ThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov191_BeginPickTarget);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov191_SetPose2ThenAdvanceSlot);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov191_stClearFlag1SetFlags86C);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov191_stClearFlag1SetFlags86B);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov191_Pose4ClearFieldsAdvance);
            break;
        }
    *(signed char *)(*state + 0x1c7) = -1;
}
