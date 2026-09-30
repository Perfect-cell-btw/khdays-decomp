/* AI step: decays the spin; when the child's animation ends queues action 2 and clears the step
 * handler. */

extern void Ov130_DecaySpinOverElapsed();
extern void SetIndexedSlot();

void Ov130_PrepSubState2IfChildIdle(int this_) {
    int n = *(int *)(this_ + 4);
    Ov130_DecaySpinOverElapsed(this_);
    if (*(unsigned char *)(*(int *)(n + 4) + 0xad)) return;
    *(char *)(*(int *)n + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
