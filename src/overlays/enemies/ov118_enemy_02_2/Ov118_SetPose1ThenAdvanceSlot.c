extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov118_KeepDistanceOrRetreat();

void Ov118_SetPose1ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov118_KeepDistanceOrRetreat);
}
