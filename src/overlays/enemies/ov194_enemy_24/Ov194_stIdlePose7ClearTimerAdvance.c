/* AI step: once the model's animation ends, posts pose 7, clears the timer and installs the timed
 * step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov194_AiStep_WaitTimerThenTag8();

void Ov194_stIdlePose7ClearTimerAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(n + 4) + 0xad)) return;
    Ov107_PostTagUpdate(*(int *)n, 7, 1);
    *(int *)(n + 0x30) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov194_AiStep_WaitTimerThenTag8);
}
