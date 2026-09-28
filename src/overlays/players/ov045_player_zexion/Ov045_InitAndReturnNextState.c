extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov045_Boot();
extern void Ov045_InitActorTwoRegionsAndForward();
extern void Ov022_RequestVoiceIds();
extern void Ov022_ArmDecoder();

void *Ov045_InitAndReturnNextState(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov045_Boot(a);
    Ov045_InitActorTwoRegionsAndForward(r);
    Ov022_RequestVoiceIds(r, 0x4a, 0xc9);
    return (void *)Ov022_ArmDecoder;
}
