/* State step: without a grabbed object queues action 2 and ends the step; otherwise finds the path
 * to its grab slot and installs the aim step. */

extern int Ov262_FindGrabSlotPath(int *state, int flag);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov262_AimTick(void);

void Ov262_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(int *)(*state + 0x3a8) == 0) {
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    state[0x1c] = Ov262_FindGrabSlotPath(state, *(unsigned char *)(*state + 0x3ac));
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov262_AimTick);
}
