/* Pauses or resumes the BGM player; returns the current BGM id when none is playing. */

extern char *gSoundMgr;
extern int NNS_SndPlayerPause(void *ptr, int arg);

int SoundMgr_PauseBgm(int arg) {
    char *base = gSoundMgr;
    int value = *(short *)(base + 0xb46f6);

    if (value < 0) {
        return value;
    }

    return NNS_SndPlayerPause(base + 0xb44c4, arg);
}
