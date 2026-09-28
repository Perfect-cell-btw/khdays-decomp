extern unsigned char *data_0204c234;
extern unsigned int NNS_SndArcStrmGetCurrentPlayingPos(void *ptr);
extern unsigned int NNS_SndArcStrmGetTimeLength(void *ptr);

int SoundMgr_GetStreamNextPos(int index) {
    unsigned int value = NNS_SndArcStrmGetCurrentPlayingPos(data_0204c234 + 0xb44bc + index * 4) + 1;

    if (value >= NNS_SndArcStrmGetTimeLength(data_0204c234 + 0xb44bc + index * 4)) {
        value = -1;
    }

    return value;
}
