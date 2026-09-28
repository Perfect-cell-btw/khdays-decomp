extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov114_ApproachTick();

void Ov114_SetPose3ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 3, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov114_ApproachTick);
}
