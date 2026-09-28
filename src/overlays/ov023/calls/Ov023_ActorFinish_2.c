/* Interworking tail-call thunk to the ov023 handler. */
extern int Ov023_ActorFinish();
int Ov023_ActorFinish_2(void) {
    return Ov023_ActorFinish();
}
