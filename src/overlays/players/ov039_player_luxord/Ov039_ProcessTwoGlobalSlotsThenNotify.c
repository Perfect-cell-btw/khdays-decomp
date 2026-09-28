/* Releases the character's two effect sequences, then frees its attached group. */

extern int data_ov039_020b5600;
extern void ReleaseField74AndCleanup();
extern void Ov039_FreeAttachedGroup();

void Ov039_ProcessTwoGlobalSlotsThenNotify(int this_) {
    int i;
    char *p = (char *)(data_ov039_020b5600 + 0x2cf0);
    for (i = 0; i < 2; i++, p += 0x10c) {
        ReleaseField74AndCleanup((int)p);
    }
    Ov039_FreeAttachedGroup(this_);
}
