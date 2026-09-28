extern void ForceStopStrm_2(void *p);
extern void NNSi_SndFaderSet(void *p, int a, int b);

struct S {
    char _0[0x110];
    int flags;
    char _114[0x150 - 0x114];
    int x150;
};

void SNDi_FreeVoiceChannel(struct S *p, int a)
{
    if (((p->flags << 30) >> 31) == 0) {
        ForceStopStrm_2(p);
        return;
    }
    if (a == 0) {
        ForceStopStrm_2(p);
        return;
    }
    NNSi_SndFaderSet((char *)p + 0xe8, 0, a);
    p->flags |= 8;
    p->x150 = 0;
}
