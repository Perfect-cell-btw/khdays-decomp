extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov184_BeginCharge();

void Ov184_SetPose2ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 2, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov184_BeginCharge);
}
