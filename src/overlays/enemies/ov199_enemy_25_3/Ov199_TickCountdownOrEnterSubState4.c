/* AI step: counts the timer down while the animation runs, keeping pose 1; when it expires, queues
 * action 4. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);

void Ov199_TickCountdownOrEnterSubState4(int *node) {
    int *state = (int *)node[1];
    state[0x10] -= *(int *)(*node + 0x2c);
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    if (state[0x10] <= 0) {
        *(signed char *)(*state + 0x1c7) = 4;
        SetIndexedSlot(node, *(signed char *)(node + 8), 0);
        return;
    }
    Ov107_PostTagUpdate(*state, 1, 0);
}
