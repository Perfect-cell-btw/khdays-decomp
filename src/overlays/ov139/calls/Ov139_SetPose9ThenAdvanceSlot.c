extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov139_GuardField50Pose10ClearAdvance();

void Ov139_SetPose9ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 9, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov139_GuardField50Pose10ClearAdvance);
}
