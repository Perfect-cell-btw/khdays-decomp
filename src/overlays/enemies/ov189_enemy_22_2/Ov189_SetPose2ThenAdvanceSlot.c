/* Posts a tag update for a pose, then installs the next step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov189_ReaimAndClose();

void Ov189_SetPose2ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate(*(int *)(*(int *)(this_ + 4)), 2, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov189_ReaimAndClose);
}
