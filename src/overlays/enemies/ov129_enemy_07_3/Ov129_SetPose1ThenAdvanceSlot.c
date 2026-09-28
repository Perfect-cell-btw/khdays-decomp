extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov129_PrepSubState4IfChildIdle();

void Ov129_SetPose1ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 1, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov129_PrepSubState4IfChildIdle);
}
