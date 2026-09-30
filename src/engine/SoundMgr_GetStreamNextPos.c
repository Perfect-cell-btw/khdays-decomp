/* Next playing position of stream slot index, or -1 at the end. */

extern unsigned char *gSoundMgr;
extern unsigned int NNS_SndArcStrmGetCurrentPlayingPos(void *ptr);
extern unsigned int NNS_SndArcStrmGetTimeLength(void *ptr);

int SoundMgr_GetStreamNextPos(int index) {
    unsigned int value = NNS_SndArcStrmGetCurrentPlayingPos(gSoundMgr + 0xb44bc + index * 4) + 1;

    if (value >= NNS_SndArcStrmGetTimeLength(gSoundMgr + 0xb44bc + index * 4)) {
        value = -1;
    }

    return value;
}
