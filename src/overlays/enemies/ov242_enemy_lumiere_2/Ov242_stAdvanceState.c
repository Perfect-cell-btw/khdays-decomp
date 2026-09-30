/* Queues action 3 and clears the step handler. */

extern void SetIndexedSlot();
void Ov242_stAdvanceState(int node) {
    *(signed char *)(*(int *)*(int *)(node + 4) + 0x1c7) = 3;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
}
