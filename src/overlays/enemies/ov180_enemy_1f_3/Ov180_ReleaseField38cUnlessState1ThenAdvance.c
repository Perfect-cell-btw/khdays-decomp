extern void Ov107_UnlinkNodeFromOwner();
extern void Ov107_AiState_PostTickBase();

void Ov180_ReleaseField38cUnlessState1ThenAdvance(int this_) {
    if (*(signed char *)(this_ + 0x1c6) != 1 && *(int *)(this_ + 0x38c) != 0) {
        Ov107_UnlinkNodeFromOwner(*(int *)(this_ + 0x38c));
        *(int *)(this_ + 0x38c) = 0;
    }
    Ov107_AiState_PostTickBase(this_);
}
