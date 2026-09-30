/* Tears the block held by gSoundMgr down: runs NNS_SndStopSoundAll once, then NNS_SndHandleReleaseSeq
 * over the sixteen 0x20-byte entries at +0xb4500 and over the two singles at +0xb44c8 and
 * +0xb44c4, and finally drops the pointer.  Returns 1 (also when nothing was allocated).
 *
 * `i` has to be declared between the two pointers to reproduce the ROM's r4/r5. */
extern char *gSoundMgr;
extern void NNS_SndStopSoundAll(void);
extern void NNS_SndHandleReleaseSeq(void *p);

int Res_TearDownBlock(void) {
    char *base;
    int i;
    char *p;
    base = gSoundMgr;
    if (base == 0) {
        return 1;
    }
    NNS_SndStopSoundAll();
    i = 0;
    p = base + 0xb4500;
    do {
        NNS_SndHandleReleaseSeq(p);
        i = i + 1;
        p = p + 0x20;
    } while (i < 0x10);
    NNS_SndHandleReleaseSeq(base + 0xb44c8);
    NNS_SndHandleReleaseSeq(base + 0xb44c4);
    gSoundMgr = 0;
    return 1;
}
