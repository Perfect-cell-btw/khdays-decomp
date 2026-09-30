/* AI step: once the actor is active, picks the current waypoint, queues the stored action and ends
 * the step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov243_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (!(((struct hw60 *)(*state + 0x60))->lo & 1)) return;
    state[7] = state[9] * 0x14 + *(int *)(*state + 0x398);
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
