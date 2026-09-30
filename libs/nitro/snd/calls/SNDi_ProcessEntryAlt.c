extern int ReleaseNodeResources(void *entry);
extern char *gEntityMgr;

int SNDi_ProcessEntryAlt(int idx) {
    char *base = gEntityMgr + 0xc4;
    return ReleaseNodeResources((void *)(0x184 * idx + (int)base));
}
