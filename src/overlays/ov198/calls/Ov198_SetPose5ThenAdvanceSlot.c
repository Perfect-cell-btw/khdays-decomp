extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov198_CopyScaleVec3ThenAdvanceSlot();

void Ov198_SetPose5ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov198_CopyScaleVec3ThenAdvanceSlot);
}
