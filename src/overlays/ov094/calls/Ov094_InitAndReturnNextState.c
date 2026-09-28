extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov094_BuildRigObject(void *obj);
extern void Ov094_ResetSequences(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int x, int y);
extern void Ov022_ArmDecoder(void);

int Ov094_InitAndReturnNextState(void *obj) {
    void *h = NNSi_FndGetCurrentRootHeap();
    Ov094_BuildRigObject(obj);
    Ov094_ResetSequences(h);
    Ov022_RequestVoiceIds(h, 0x49, 0xc8);
    return (int)Ov022_ArmDecoder;
}
