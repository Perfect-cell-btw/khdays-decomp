/* AI step: once the gate byte is clear, sets the step value to 0x2000, queues action 2 and clears
 * the step handler. */

extern void SetIndexedSlot();

void Ov293_AdvanceStateSetField18_2(int this_) {
    int node = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(node + 0x4c)) != 0) return;
    *(int *)(node + 0x18) = 0x1000;
    *(signed char *)(*(int *)node + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
