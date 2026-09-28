extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov203_BeginRecoil();

void Ov203_SetPose6ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 6, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov203_BeginRecoil);
}
