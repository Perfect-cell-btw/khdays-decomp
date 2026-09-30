/*
 * Ov201_WireSubNodesRegister2 -- x3. AI-state entry: wire up the sub-nodes and their hit regions, register two
 * handlers. Mark bit1 of *(node+0x5c) on each sub-node state[1..4]. On the first sub-node state[1] also
 * install the physics callback Ov201_PushTowardAnchorMidpoint at +0x6c and back-link the state at +0x84, then arm
 * its region 0 (0203b9fc). Arm state[2] regions 0/2/4 and state[4] regions 0/2 (state[3] is only
 * flagged). Set the hi nibble of state[0xe] to 0xf, clear state[0x14], clear the lo nibble of state[0xe].
 * Register handlers 0 and 1 via 0203c634 -> 020d06a4, 020d0764.
 */
struct nib { unsigned lo : 4, hi : 4; };
extern void SetSubitemState(int a, int b, int c, int d);
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov201_PushTowardAnchorMidpoint(void);
extern void Ov201_AiDispatch(void);
extern void Ov201_HideAll(void);

void Ov201_WireSubNodesRegister2(int *self) {
    int *state = (int *)self[1];

    *(int *)(state[1] + 0x5c) |= 2;
    *(int *)(state[1] + 0x6c) = (int)&Ov201_PushTowardAnchorMidpoint;
    *(int *)(state[1] + 0x84) = (int)state;
    SetSubitemState(state[1], 0, 0, 1);
    *(int *)(state[2] + 0x5c) |= 2;
    SetSubitemState(state[2], 0, 0, 1);
    SetSubitemState(state[2], 2, 0, 1);
    SetSubitemState(state[2], 4, 0, 1);
    *(int *)(state[3] + 0x5c) |= 2;
    *(int *)(state[4] + 0x5c) |= 2;
    SetSubitemState(state[4], 0, 0, 1);
    SetSubitemState(state[4], 2, 0, 1);
    ((struct nib *)(state + 0xe))->hi = 0xf;
    state[0x14] = 0;
    ((struct nib *)(state + 0xe))->lo = 0;
    SetIndexedSlot((int)self, 0, (int)&Ov201_AiDispatch);
    SetIndexedSlot((int)self, 1, (int)&Ov201_HideAll);
}
