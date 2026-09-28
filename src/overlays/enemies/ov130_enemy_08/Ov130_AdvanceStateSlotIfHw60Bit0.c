/* AI step: once the actor is active (bit 0 of its flags at +0x60), clears the timer, makes the
 * stored action (+0x1c9) pending and clears the step handler. */

extern void SetIndexedSlot();

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov130_AdvanceStateSlotIfHw60Bit0(int this_) {
    int node = *(int *)(this_ + 4);
    if ((((struct hw60 *)(*(int *)node + 0x60))->lo & 1) == 0) return;
    *(int *)(node + 0x3c) = 0;
    *(signed char *)(*(int *)node + 0x1c7) = *(signed char *)(*(int *)node + 0x1c9);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
