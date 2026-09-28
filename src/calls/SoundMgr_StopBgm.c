extern unsigned char *data_0204c234;
extern void NNS_SndPlayerStopSeq(void *ptr, int arg);

void SoundMgr_StopBgm(int arg) {
    unsigned char *base = data_0204c234;

    *(short *)(base + 0xb46f6) = -1;
    NNS_SndPlayerStopSeq(base + 0xb44c4, arg);
    *(int *)(base + 0xb4700) = arg;
    *(unsigned char *)(base + 0xb46fc) = 4;
}
