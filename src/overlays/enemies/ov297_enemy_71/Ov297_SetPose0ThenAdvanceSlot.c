extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov297_TickTimerOrEnterSubState2();

void Ov297_SetPose0ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 0, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov297_TickTimerOrEnterSubState2);
}
