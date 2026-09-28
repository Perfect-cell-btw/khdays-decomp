extern void ReleaseField74AndCleanup(int p);

void Ov080_FreeSubObjectArrayAndTailSlots(int this_) {
    char *base = (char *)(this_ + 0x2c84);
    int i;
    char *p = base + 0x334;
    for (i = 0; i < 3; i++) {
        ReleaseField74AndCleanup((int)p);
        p += 0x110;
    }
    ReleaseField74AndCleanup((int)(base + 4));
    ReleaseField74AndCleanup((int)(base + 0x114));
    ReleaseField74AndCleanup((int)(base + 0x224));
}
