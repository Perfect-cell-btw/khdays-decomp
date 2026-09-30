extern void NNS_SndPlayerStopSeqBySeqArcIdx(int obj, int index, int fadeFrame);
extern char *gSoundMgr;
/* Forward to the handler, defaulting to the session's current object (*(global)+0x9c). */
void ForwardToHandlerOrCurrentObject(int obj, int index, int fadeFrame) {
    if (obj == 0) {
        obj = *(int *)((int)gSoundMgr + 0x9c);
    }
    NNS_SndPlayerStopSeqBySeqArcIdx(obj, index, fadeFrame);
}
