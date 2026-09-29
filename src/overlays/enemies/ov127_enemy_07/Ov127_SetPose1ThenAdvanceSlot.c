/* Posts a tag update for a pose, then installs the next step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov127_PrepSubState4IfChildIdle();

void Ov127_SetPose1ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 1, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov127_PrepSubState4IfChildIdle);
}
