/* Timed step: derives the speed from the owner's frame step, eases the lift toward 1.0, faces the
 * anchor, and when the timer reaches 1.0 queues action 2 and clears the step handler. */

extern void Ov262_SetFacingAnchor();
extern void SetIndexedSlot(void *obj, int idx, void *value);
void Ov262_stateDualTimerDivide(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[0xf] = v / 5;
    }
    {
        int w = 0x1000 - *(int *)(*state + 0x13c);
        state[0xd] = state[0xd] + w / 50;
    }
    Ov262_SetFacingAnchor(state + 7, *(int *)(*state + 0x3a8) + 0x74, state[1]);
    {
        int t = state[0x10] + *(int *)(*node + 0x2c);
        state[0x10] = t;
        if (t < 0x1000) return;
    }
    state[0xb] = 0;
    *(signed char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
