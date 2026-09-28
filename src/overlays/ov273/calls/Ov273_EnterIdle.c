/* Idle entry: plays pose 0 (looping), rolls a random turn direction into +0x18, sets the
 * +0x48 rate to 30/10 of the frame step and, if the +0x6c wait is spent, re-rolls it between
 * the actor's +0x224/+0x228 bounds; then moves the node to 020cdde4. */
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern int RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov273_IdleTick(void);
void Ov273_EnterIdle(int *node) {
    int *state = (int *)node[1];
    int v;
    Ov107_PostTagUpdate(*state, 0, 1);
    /* +(v-v) forces `adds r0,r0,#0` (rand result copied+tested); +0 would fold away */
    state[6] = (RandNextScaled(2) + (v - v)) != 0 ? -1 : 1;
    state[0x12] = *(int *)(node[0] + 0x2c) * 30 / 10;
    if (state[0x1b] <= 0) {
        int lo = *(int *)(*state + 0x224);
        int d = *(int *)(*state + 0x228) - lo;
        if (d < 0) d = -d;
        state[0x1b] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov273_IdleTick);
}
