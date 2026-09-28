/* Attack wind-up tick: sets the +0x48 rate to 30/5 of the frame step; while the +0x6a latch is
 * clear the +0x70 timer runs and past 0xbbb the latch is set and effect 0x162 (kind 0xb) is
 * spawned at the +4 anchor. Unless the +8 flag byte is set, pose 0x15 plays and the node moves
 * to 020cf81c. */
extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov273_WindupTickB(void);

void Ov273_WindupTickA(int *node) {
    int *state = (int *)node[1];
    state[0x12] = *(int *)(node[0] + 0x2c) * 30 / 5;
    if (*((unsigned char *)state + 0x6a) == 0) {
        state[0x1c] += *(int *)(node[0] + 0x2c);
        if (state[0x1c] >= 0xbbb) {
            *((unsigned char *)state + 0x6a) = 1;
            Ov107_BuildAndSendUpdate(state[0], 0x162, 0xb, (void *)state[1]);
        }
    }
    if (*(unsigned char *)state[2] != 0) return;
    Ov107_PostTagUpdate(*state, 0x15, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov273_WindupTickB);
}
