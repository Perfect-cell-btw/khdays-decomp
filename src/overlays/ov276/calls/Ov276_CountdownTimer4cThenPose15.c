extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov276_AiStep_QueueAction2OnAnimEnd();

void Ov276_CountdownTimer4cThenPose15(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int v = *(int *)(b + 0x4c) - *(int *)(a + 0x2c);
    *(int *)(b + 0x4c) = v;
    if (v > 0) return;
    Ov107_PostTagUpdate(*(int *)b, 0x15, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov276_AiStep_QueueAction2OnAnimEnd);
}
