extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov127_AiStep_QueueAction4OnAnimEnd();

void Ov127_SetPose3ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 3, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov127_AiStep_QueueAction4OnAnimEnd);
}
