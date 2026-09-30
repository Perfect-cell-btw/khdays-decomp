/* Initialises the player actor: boots it, registers its sequence, requests its voices and starts
 * the mission; returns the decoder step. */

typedef void (*Ov072Handler)(void);

extern unsigned char *NNSi_FndGetCurrentRootHeap(void);
extern void Ov072_Boot(void *arg);
extern int Snd_RegisterSeqAndBind(void *slot, int arg1, int seq_id, int arg3);
extern void Ov022_RequestVoiceIds(void *ctx, int a, int b);
extern void Ov072_MissionStart(void *ctx);
extern void Ov022_ArmDecoder(void);

extern char gOv072XigbarEtcPackPath[];

Ov072Handler Ov072_InitAndGetHandler(int *arg) {
    unsigned char *ctx;

    ctx = NNSi_FndGetCurrentRootHeap();
    ctx[0x2c30] &= ~1;
    ctx[0x2c30] &= ~4;
    Ov072_Boot(arg);
    Snd_RegisterSeqAndBind(ctx + 0x2e44, *(int *)(ctx + 0x20) + 4,
                  (int)gOv072XigbarEtcPackPath, *arg + 7);
    Ov022_RequestVoiceIds(ctx, 0x43, 0xc5);
    Ov072_MissionStart(ctx);
    return Ov022_ArmDecoder;
}
