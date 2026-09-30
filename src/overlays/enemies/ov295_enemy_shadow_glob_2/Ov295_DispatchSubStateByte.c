/* State dispatcher: when an action is pending (+0x1c7 not -1) resets the per-action flags, makes it
 * current (+0x1c6; action 1 becomes 2) and installs the step that runs it; then marks nothing
 * pending. */

struct bf { unsigned b : 8; };
struct st1c6 { signed char _pad[0x1c6]; signed char sub; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov295_stSetDispFlagsde(void);
extern void Ov295_TickEnemyAi(void);
extern void Ov295_ConfigHw60FlagsAndBeginAction4(void);

void Ov295_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        ((struct hw60 *)(*state + 0x60))->hi &= ~0x8a;
        *(unsigned short *)(*state + 0x1ae) &= ~0x1;
        ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov295_stSetDispFlagsde);
            break;
        case 1:
            ((struct st1c6 *)*state)->sub = 2;
            /* fall through */
        case 2:
            SetIndexedSlot(node, 1, Ov295_TickEnemyAi);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov295_ConfigHw60FlagsAndBeginAction4);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
