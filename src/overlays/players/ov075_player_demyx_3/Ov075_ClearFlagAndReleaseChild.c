extern int ReleaseField74AndCleanup(void *);

int Ov075_ClearFlagAndReleaseChild(void *obj) {
    char *p = (char *)obj + 0x2c80;
    *(int *)p = 0;
    return ReleaseField74AndCleanup(p + 0xc);
}
