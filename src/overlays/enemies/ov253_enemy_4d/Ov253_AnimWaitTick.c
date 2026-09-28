/* Ov253_AnimWaitTick -- animation wait: the +0x1c timer runs up by the frame step; once the
 * +4 item's animation is free (byte 0 clear) the +0x34 repeat count grows: under 2 pose 0xb
 * plays again, otherwise pose 8 and the node moves to 020ce210. */
extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_RoarTick(void);

void Ov253_AnimWaitTick(int *node) {
    int *state = (int *)node[1];

    state[7] += *(int *)(node[0] + 0x2c);
    if (*(unsigned char *)state[1] != 0) {
        return;
    }
    state[0xd]++;
    if (state[0xd] < 2) {
        Ov107_PostTagUpdate(*state, 0xb, 0);
        return;
    }
    Ov107_PostTagUpdate(*state, 8, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_RoarTick);
}
