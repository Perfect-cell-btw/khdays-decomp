extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov100_Boot(void *obj);
extern void Ov100_InitActorTwoRegionsAndForward(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int x, int y);
extern void Ov022_ArmDecoder(void);

int Ov100_InitAndReturnNextState(void *obj) {
    void *h = NNSi_FndGetCurrentRootHeap();
    Ov100_Boot(obj);
    Ov100_InitActorTwoRegionsAndForward(h);
    Ov022_RequestVoiceIds(h, 0x4a, 0xc9);
    return (int)Ov022_ArmDecoder;
}
