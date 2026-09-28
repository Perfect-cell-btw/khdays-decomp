/* Ov245_NodeInit2 -- node initialiser: resets the actor's +0x1c6 state and +0x1c7 request,
 * clears bit 0 of the +0x3b4 item's +8 low byte, sets the state's +0x24 to 3.14 (0x3244) and
 * points +8 at the actor's +0xb0 pose, raises bits 1, 2 and 4 and clears bits 3
 * and 6 of the +0x60 high byte, and installs the three slot handlers (1: 020cd668, 0: 020ccfa8,
 * 2: 020cd1d0). */
typedef unsigned short u16;
struct w8 { unsigned int lo : 8, rest : 24; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_stateSetFlagsClearBit(void);
extern void Ov245_CommitQueuedMove(void);
extern void Ov245_BossMotionTick(void);

void Ov245_NodeInit2(int *node) {
    int *state = (int *)node[1];

    *(unsigned char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo &= ~1;
    state[9] = 0x3244;
    state[2] = *state + 0xb0;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x16) << 0x18) >> 0x10);
    }
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0x48) << 0x18) >> 0x10);
    }
    SetIndexedSlot(node, 1, Ov245_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, Ov245_CommitQueuedMove);
    SetIndexedSlot(node, 2, Ov245_BossMotionTick);
}
