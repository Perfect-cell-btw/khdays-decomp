/* AI step: posts pose 0 and continues. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov291_stAdvanceState();

void Ov291_SetPose0ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 0, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov291_stAdvanceState);
}
