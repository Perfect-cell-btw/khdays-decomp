extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov196_AiStep_WaitTimerThenTag8();

void Ov196_stIdlePose7ClearTimerAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(n + 4) + 0xad)) return;
    Ov107_PostTagUpdate(*(int *)n, 7, 1);
    *(int *)(n + 0x30) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov196_AiStep_WaitTimerThenTag8);
}
