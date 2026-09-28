extern void ReleaseField74AndCleanup(int p);
extern int data_ov094_020bc240;

void Ov094_FreeFiveGlobalSubObjects(void) {
    char *base = (char *)(data_ov094_020bc240 + 0x2c2c);
    ReleaseField74AndCleanup((int)(base + 0x22c));
    ReleaseField74AndCleanup((int)(base + 0x10));
    ReleaseField74AndCleanup((int)(base + 0x11c));
    ReleaseField74AndCleanup((int)(base + 0x33c));
    ReleaseField74AndCleanup((int)(base + 0x448));
}
