extern void *data_ov056_020b7620;
extern void ReleaseField74AndCleanup(void *p);

void Ov056_ReleaseBothSlots(void) {
    char *base = (char *)data_ov056_020b7620 + 0x2c2c;
    ReleaseField74AndCleanup(base + 4);
    ReleaseField74AndCleanup(base + 0x120);
}
