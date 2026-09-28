extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov216_AimAndFacePointTick();

void Ov216_SetPose2ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 2, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov216_AimAndFacePointTick);
}
