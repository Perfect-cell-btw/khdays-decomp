extern void NNS_SndArcStrmPrepare(int, int, int);
extern int data_0204c234;

void SoundMgr_PrepareStream(int param_1, int param_2) {
    NNS_SndArcStrmPrepare(data_0204c234 + 0xb44bc + param_1 * 4, param_2, 0);
}
