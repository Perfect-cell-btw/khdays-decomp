/* Starts a stream on one of the stream players and records the stream id. */

extern void NNS_SndArcStrmStart();
extern int gSoundMgr;

void StampByteAndInvokeSubStructAt(int arg0, int arg1) {
    *(unsigned char *)(gSoundMgr + 0xb47b7) = arg1;
    NNS_SndArcStrmStart(gSoundMgr + 0xb44bc + (arg0 << 2), arg1, 0);
}
