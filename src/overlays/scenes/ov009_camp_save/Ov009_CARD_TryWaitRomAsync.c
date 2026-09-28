/* Interworking tail-call thunk to the ov023 handler. */
extern int CARD_TryWaitRomAsync();
int Ov009_CARD_TryWaitRomAsync(void) {
    return CARD_TryWaitRomAsync();
}
