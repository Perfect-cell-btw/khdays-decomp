/* True when the stream slot's current playing position is non-zero. */

extern char *gSoundMgr;
extern int NNS_SndArcStrmGetCurrentPlayingPos(void *ptr);

int SoundStrm_HasPlaybackPos(int index) {
    return NNS_SndArcStrmGetCurrentPlayingPos(gSoundMgr + 0xb44bc + index * 4) != 0;
}
