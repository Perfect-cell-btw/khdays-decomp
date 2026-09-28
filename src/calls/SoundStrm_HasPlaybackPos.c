extern char *data_0204c234;
extern int NNS_SndArcStrmGetCurrentPlayingPos(void *ptr);

int SoundStrm_HasPlaybackPos(int index) {
    return NNS_SndArcStrmGetCurrentPlayingPos(data_0204c234 + 0xb44bc + index * 4) != 0;
}
