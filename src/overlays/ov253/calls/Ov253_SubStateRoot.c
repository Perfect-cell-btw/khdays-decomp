/* Ov253_SubStateRoot -- sub-state root: clears the actor's +0x1c6 kind and +0x1c7 sub-state
 * (-1), points the state at the actor's +0xb0 / +0x74 vectors and the +0x384 item's +0xad
 * flag, raises bits 1-4 and 6 of the +0x60 high byte and installs the three sub-nodes
 * (slot 1: 020d2a34, slot 0: 020d2934, slot 2: 020d2a30). */
typedef unsigned short u16;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_stSetDispFlags82_2(void);
extern void Ov253_SubStateDispatch(void);
extern void Ov253_AiSlot2NoOp(void);

void Ov253_SubStateRoot(int *node) {
    int *state = (int *)node[1];

    *(unsigned char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    state[1] = *state + 0xb0;
    state[2] = *state + 0x74;
    state[3] = *(int *)(*state + 0x384) + 0xad;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x5e) << 0x18) >> 0x10);
    }
    SetIndexedSlot(node, 1, Ov253_stSetDispFlags82_2);
    SetIndexedSlot(node, 0, Ov253_SubStateDispatch);
    SetIndexedSlot(node, 2, Ov253_AiSlot2NoOp);
}
