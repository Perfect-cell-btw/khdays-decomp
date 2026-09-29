/* Posts a tag update for a pose, then installs the next step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov164_EnterRecoil();

void Ov164_SetPose6ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 6, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov164_EnterRecoil);
}
