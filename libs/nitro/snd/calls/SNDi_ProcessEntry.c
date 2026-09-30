extern int Render_ReleaseNodeItem(void *entry);
extern char *gEntityMgr;

int SNDi_ProcessEntry(int idx) {
    char *base = gEntityMgr + 0xc4;
    return Render_ReleaseNodeItem((void *)(0x184 * idx + (int)base));
}
