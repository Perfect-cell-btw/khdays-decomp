/* Clears three fields of the global state block. */

extern int gSoundMgr;

void ClearGlobalFields80to84(void) {
    int base = *(int *)&gSoundMgr + 0xb4718;
    *(short *)(base + 0x80) = 0;
    *(short *)(base + 0x82) = 0;
    *(char *)(base + 0x84) = 0;
}
