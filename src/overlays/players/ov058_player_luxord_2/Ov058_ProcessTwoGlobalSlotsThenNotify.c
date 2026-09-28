/* Releases the character's two effect sequences, then frees its attached group. */

extern int data_ov058_020b7e00;
extern void ReleaseField74AndCleanup();
extern void Ov058_FreeAttachedGroup();

void Ov058_ProcessTwoGlobalSlotsThenNotify(int this_) {
    int i;
    char *p = (char *)(data_ov058_020b7e00 + 0x2cf0);
    for (i = 0; i < 2; i++, p += 0x10c) {
        ReleaseField74AndCleanup((int)p);
    }
    Ov058_FreeAttachedGroup(this_);
}
