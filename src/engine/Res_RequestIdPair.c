/* Issues one request through Loader_PostTypedRequest for the id pair (n, n + 0x25) against the
 * table 0xb04a0 bytes into the block held by gSoundMgr, using a stack byte as the
 * out-parameter, then lets Loader_SleepIfBusy consume it. */
extern char *gSoundMgr;
extern void Loader_PostTypedRequest(unsigned short a, unsigned short b, int c, unsigned char *d);
extern void Loader_SleepIfBusy(void);

void Res_RequestIdPair(int n) {
    unsigned char flag = 0;
    Loader_PostTypedRequest((unsigned short)n, (unsigned short)(n + 0x25),
                  *(int *)(gSoundMgr + 0xb04a0), &flag);
    Loader_SleepIfBusy();
}
