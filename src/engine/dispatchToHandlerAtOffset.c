/* Sets the volume of the BGM player. */

extern int gSoundMgr;
extern void *NNS_SndPlayerSetVolume();
void *dispatchToHandlerAtOffset(int param_1) {
    return NNS_SndPlayerSetVolume(gSoundMgr + 0xb44c8, param_1);
}
