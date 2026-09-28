extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov181_GuardFieldCClearField1cAdvance();

void Ov181_SetPose5ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov181_GuardFieldCClearField1cAdvance);
}
