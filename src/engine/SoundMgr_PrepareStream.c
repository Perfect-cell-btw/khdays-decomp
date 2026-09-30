/* Prepares stream slot index with the stream id. */

extern void NNS_SndArcStrmPrepare(int, int, int);
extern int gSoundMgr;

void SoundMgr_PrepareStream(int param_1, int param_2) {
    NNS_SndArcStrmPrepare(gSoundMgr + 0xb44bc + param_1 * 4, param_2, 0);
}
