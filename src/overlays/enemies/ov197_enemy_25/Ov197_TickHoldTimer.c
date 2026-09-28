/* Count the hold timer down by the owner's per-frame delta and, once the sub-object is no
 * longer busy, either keep the idle animation running or -- when the timer has run out --
 * publish action 4 and hand off with no callback.
 *
 * Matched byte-exact 2026-07-23, first compile. The timer is RE-READ after the busy check
 * rather than kept in a register, which is why the guard is written as a second load.
 *
 * One of four byte-identical siblings. */
extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *cb);

void Ov197_TickHoldTimer(int *node) {
    int *owner = (int *)node[0];
    int *state = (int *)node[1];

    state[0x10] = state[0x10] - *(int *)((int)owner + 0x2c);
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    if (state[0x10] <= 0) {
        *(char *)(state[0] + 0x1c7) = 4;
        SetIndexedSlot(node, *(signed char *)((int)node + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate(state[0], 1, 0);
}
