extern void *data_ov037_020b4e20;
extern void ReleaseField74AndCleanup(void *p);

void Ov037_ReleaseBothSlots(void) {
    char *base = (char *)data_ov037_020b4e20 + 0x2c2c;
    ReleaseField74AndCleanup(base + 4);
    ReleaseField74AndCleanup(base + 0x120);
}
