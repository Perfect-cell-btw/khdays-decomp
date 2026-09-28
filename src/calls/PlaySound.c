extern char *data_0204c234;
extern int NNS_SndArcPlayerStartSeqArc(void *ptr, int arg1, int arg2);

int PlaySound(int arg0, int arg1) {
    if (arg0 == 0) {
        arg0 = *(int *)(data_0204c234 + 0x9c);
    }

    return NNS_SndArcPlayerStartSeqArc(data_0204c234 + 0xb44c8, arg0, arg1);
}
