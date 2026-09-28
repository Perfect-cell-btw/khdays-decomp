/* AI step: once the actor is active, resets its motion values, queues its stored action and ends
 * the step. */

extern void SetIndexedSlot();

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov292_AdvanceStateSlotIfHw60Bit0(int this_) {
    int node = *(int *)(this_ + 4);
    if ((((struct hw60 *)(*(int *)node + 0x60))->lo & 1) == 0) return;
    *(int *)(node + 0x2c) = 0;
    *(int *)(node + 0x34) = 0;
    *(int *)(node + 0x30) = 0x1000;
    *(signed char *)(*(int *)node + 0x1c7) = *(signed char *)(*(int *)node + 0x1c9);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
