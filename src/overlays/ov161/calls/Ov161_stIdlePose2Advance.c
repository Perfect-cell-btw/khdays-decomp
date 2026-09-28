extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov161_stSeekTargetSteer();

void Ov161_stIdlePose2Advance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x48)) return;
    Ov107_PostTagUpdate(*(int *)n, 2, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov161_stSeekTargetSteer);
}
