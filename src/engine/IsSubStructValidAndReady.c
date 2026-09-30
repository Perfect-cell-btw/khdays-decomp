/* Whether the BGM player has a sequence and it is still playing. */

extern int gSoundMgr;
extern int NNS_SndPlayerGetSeqNo();
extern int NNS_SndPlayerCountPlayingSeqBySeqNo();

int IsSubStructValidAndReady(void) {
    int r = NNS_SndPlayerGetSeqNo(gSoundMgr + 0xb44c4);
    if (r < 0) goto ret0;
    if (NNS_SndPlayerCountPlayingSeqBySeqNo(r) != 0) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
