extern void ReleaseField74AndCleanup(int p);
extern int data_ov038_020b4ca0;

void Ov038_FreeFiveGlobalSubObjects(void) {
    char *base = (char *)(data_ov038_020b4ca0 + 0x2c2c);
    ReleaseField74AndCleanup((int)(base + 0x22c));
    ReleaseField74AndCleanup((int)(base + 0x10));
    ReleaseField74AndCleanup((int)(base + 0x11c));
    ReleaseField74AndCleanup((int)(base + 0x33c));
    ReleaseField74AndCleanup((int)(base + 0x448));
}
