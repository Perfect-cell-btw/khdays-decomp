extern void Ov107_PostTagUpdate();
extern void Ov240_startAnim();
extern void SetIndexedSlot();
extern void Ov240_SpinTick();

void Ov240_PoseResetTimerFieldsThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 7, 0);
    Ov240_startAnim(*(int *)node, 2);
    *(int *)(node + 0x38) = 0;
    *(unsigned char *)(node + 0x3e) = 0;
    *(unsigned char *)(node + 0x3c) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov240_SpinTick);
}
