/* Ov253_ShoutTick -- shout tick: the +0x18 speed follows twice the frame step (30 / 15) and
 * the +0x1c timer runs up; past 0.797 (latched at +0x32) reaction 0x16c/9 fires at the +4
 * anchor. Once the +8 item's animation is free pose 3 plays, the timer and latch clear and the
 * node moves to 020cfd20. */
extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_GrabTick(void);

void Ov253_ShoutTick(int *node) {
    int *state = (int *)node[1];

    state[6] = *(int *)(node[0] + 0x2c) * 0x1e / 0xf;
    state[7] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x32) == 0 && state[7] >= 0xcc0) {
        *((unsigned char *)state + 0x32) = 1;
        Ov107_BuildAndSendUpdate(*state, 0x16c, 9, (void *)state[1]);
    }
    if (*(unsigned char *)state[2] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 3, 0);
    state[7] = 0;
    *((unsigned char *)state + 0x32) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_GrabTick);
}
