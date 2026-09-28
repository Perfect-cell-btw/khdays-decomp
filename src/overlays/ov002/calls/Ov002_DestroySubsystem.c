extern void Ov002_ReleaseResources(void);
extern int NNSi_FndFreeFromDefaultHeap(int block);
extern char *data_ov002_0207fa14;
/* Tear down the subsystem: release its resources, free the inner buffer and clear its two header
 * words, then free the context itself and null the global slot. */
void Ov002_DestroySubsystem(void) {
    int *ctx = (int *)data_ov002_0207fa14;
    Ov002_ReleaseResources();
    if (*ctx != 0) {
        NNSi_FndFreeFromDefaultHeap(*ctx);
        ctx[0] = 0;
        ctx[1] = 0;
    }
    NNSi_FndFreeFromDefaultHeap((int)data_ov002_0207fa14);
    data_ov002_0207fa14 = 0;
}
