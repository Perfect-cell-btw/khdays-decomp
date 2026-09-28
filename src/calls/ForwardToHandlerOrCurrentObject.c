extern void NNS_SndPlayerStopSeqBySeqArcIdx(int obj);
extern char *data_0204c234;
/* Forward to the handler, defaulting to the session's current object (*(global)+0x9c). */
void ForwardToHandlerOrCurrentObject(int obj) {
    if (obj == 0) {
        obj = *(int *)((int)data_0204c234 + 0x9c);
    }
    NNS_SndPlayerStopSeqBySeqArcIdx(obj);
}
