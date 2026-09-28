/* AI step: keeps facing the chase target; when the child's animation ends queues action 4 and
 * clears the step handler. */

extern void Ov130_UpdateChaseFacing();
extern void SetIndexedSlot();

void Ov130_PrepSubState4IfChildIdle(int this_) {
    int n = *(int *)(this_ + 4);
    Ov130_UpdateChaseFacing(this_);
    if (*(unsigned char *)(*(int *)(n + 4) + 0xad)) return;
    *(char *)(*(int *)n + 0x1c7) = 4;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
