/* AI step: while the counter at +0x14 is below 0x80, clears the timer, posts pose 2 and installs
 * the fixed-angle move step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov143_stateFixedAngleMove();

void Ov143_PoseAdvanceUnlessField14AtLeast80(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(int *)(n + 0x14) >= 0x80) return;
    *(int *)(n + 0x30) = 0;
    Ov107_PostTagUpdate(*(int *)n, 2, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov143_stateFixedAngleMove);
}
