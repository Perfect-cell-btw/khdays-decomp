/* Starts stream slot index at the position with the manager's volume. */

extern int NNS_SndArcStrmStart(void *a0, unsigned int a1, int a2);
extern unsigned char *data_0204c234;

int SoundMgr_StartStream(int arg0, int arg1)
{
    unsigned char *base = data_0204c234;
    return NNS_SndArcStrmStart(base + 0xb44bc + arg0 * 4, base[0xb47b7], arg1);
}
