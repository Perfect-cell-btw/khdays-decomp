extern void ReleaseField74AndCleanup(int p);
extern int data_ov077_020b9b80;

void Ov077_FreeFiveGlobalSubObjects(void) {
    char *base = (char *)(data_ov077_020b9b80 + 0x2c2c);
    ReleaseField74AndCleanup((int)(base + 0x22c));
    ReleaseField74AndCleanup((int)(base + 0x10));
    ReleaseField74AndCleanup((int)(base + 0x11c));
    ReleaseField74AndCleanup((int)(base + 0x33c));
    ReleaseField74AndCleanup((int)(base + 0x448));
}
