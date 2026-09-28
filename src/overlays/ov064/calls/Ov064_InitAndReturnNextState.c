extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov064_Boot(void *obj);
extern void Ov064_InitActorTwoRegionsAndForward(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int x, int y);
extern void Ov022_ArmDecoder(void);

int Ov064_InitAndReturnNextState(void *obj) {
    void *h = NNSi_FndGetCurrentRootHeap();
    Ov064_Boot(obj);
    Ov064_InitActorTwoRegionsAndForward(h);
    Ov022_RequestVoiceIds(h, 0x4a, 0xc9);
    return (int)Ov022_ArmDecoder;
}
