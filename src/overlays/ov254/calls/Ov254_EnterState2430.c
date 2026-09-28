/* Ov254_EnterState2430 -- entry of a sub-state: clears the actor's +0x388 handle, raises bit 7
 * and clears bit 0 of the +0x60 high byte, and installs 020d2430 in the node's slot. */
typedef unsigned short u16;
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov254_IdleStep(void);

void Ov254_EnterState2430(int *node) {
    int *state = (int *)node[1];

    *(int *)(*state + 0x388) = 0;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x80) << 0x18) >> 0x10);
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov254_IdleStep);
}
