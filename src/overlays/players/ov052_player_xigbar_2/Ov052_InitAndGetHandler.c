typedef void (*Ov052Handler)(void);

extern unsigned char *NNSi_FndGetCurrentRootHeap(void);
extern void Ov052_Boot(void *arg);
extern int Snd_RegisterSeqAndBind(void *slot, int arg1, int seq_id, int arg3);
extern void Ov022_RequestVoiceIds(void *ctx, int a, int b);
extern void Ov052_MissionStart(void *ctx);
extern void Ov022_ArmDecoder(void);

extern char data_ov052_020b8008[];

Ov052Handler Ov052_InitAndGetHandler(int *arg) {
    unsigned char *ctx;

    ctx = NNSi_FndGetCurrentRootHeap();
    ctx[0x2c30] &= ~1;
    ctx[0x2c30] &= ~4;
    Ov052_Boot(arg);
    Snd_RegisterSeqAndBind(ctx + 0x2e44, *(int *)(ctx + 0x20) + 4,
                  (int)data_ov052_020b8008, *arg + 7);
    Ov022_RequestVoiceIds(ctx, 0x43, 0xc5);
    Ov052_MissionStart(ctx);
    return Ov022_ArmDecoder;
}
