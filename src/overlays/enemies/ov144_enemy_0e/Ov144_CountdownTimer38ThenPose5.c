extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov144_stateScanSlotRoundRobin();

void Ov144_CountdownTimer38ThenPose5(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int v = *(int *)(b + 0x38) - *(int *)(a + 0x2c);
    *(int *)(b + 0x38) = v;
    if (v > 0) return;
    Ov107_PostTagUpdate(*(int *)b, 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov144_stateScanSlotRoundRobin);
}
