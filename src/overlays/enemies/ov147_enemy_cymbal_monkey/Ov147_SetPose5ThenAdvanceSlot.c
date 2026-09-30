/* Posts a tag update for a pose, then installs the next step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov147_CopyScaleVec3ThenAdvanceSlot();

void Ov147_SetPose5ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov147_CopyScaleVec3ThenAdvanceSlot);
}
