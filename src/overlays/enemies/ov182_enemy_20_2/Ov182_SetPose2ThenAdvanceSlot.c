extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov182_BeginCharge();

void Ov182_SetPose2ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 2, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov182_BeginCharge);
}
