/* Releases the character's two effect sequences, then frees its attached group. */

extern int data_ov078_020ba4e0;
extern void ReleaseField74AndCleanup();
extern void Ov078_FreeAttachedGroup();

void Ov078_ProcessTwoGlobalSlotsThenNotify(int this_) {
    int i;
    char *p = (char *)(data_ov078_020ba4e0 + 0x2cf0);
    for (i = 0; i < 2; i++, p += 0x10c) {
        ReleaseField74AndCleanup((int)p);
    }
    Ov078_FreeAttachedGroup(this_);
}
