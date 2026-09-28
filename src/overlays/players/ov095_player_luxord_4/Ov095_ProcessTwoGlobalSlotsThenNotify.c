extern int data_ov095_020bcba0;
extern void ReleaseField74AndCleanup();
extern void Ov095_FreeAttachedGroup();

void Ov095_ProcessTwoGlobalSlotsThenNotify(int this_) {
    int i;
    char *p = (char *)(data_ov095_020bcba0 + 0x2cf0);
    for (i = 0; i < 2; i++, p += 0x10c) {
        ReleaseField74AndCleanup((int)p);
    }
    Ov095_FreeAttachedGroup(this_);
}
