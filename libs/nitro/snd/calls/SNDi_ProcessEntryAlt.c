extern int ReleaseNodeResources(void *entry);
extern char *data_0204c208;

int SNDi_ProcessEntryAlt(int idx) {
    char *base = data_0204c208 + 0xc4;
    return ReleaseNodeResources((void *)(0x184 * idx + (int)base));
}
