extern char *data_0204c234;
extern int NNS_SndPlayerPause(void *ptr, int arg);

int SoundMgr_PauseBgm(int arg) {
    char *base = data_0204c234;
    int value = *(short *)(base + 0xb46f6);

    if (value < 0) {
        return value;
    }

    return NNS_SndPlayerPause(base + 0xb44c4, arg);
}
