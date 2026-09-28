extern int data_0204c234;
extern void *NNS_SndPlayerSetVolume();
void *dispatchToHandlerAtOffset(int param_1) {
    return NNS_SndPlayerSetVolume(data_0204c234 + 0xb44c8, param_1);
}
