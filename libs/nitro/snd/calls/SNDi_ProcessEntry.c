extern int Render_ReleaseNodeItem(void *entry);
extern char *data_0204c208;

int SNDi_ProcessEntry(int idx) {
    char *base = data_0204c208 + 0xc4;
    return Render_ReleaseNodeItem((void *)(0x184 * idx + (int)base));
}
