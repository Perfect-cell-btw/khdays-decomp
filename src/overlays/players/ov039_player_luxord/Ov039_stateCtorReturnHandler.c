extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov039_Boot(int a);
extern void Ov039_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov039_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov039_Boot(param);
    Ov039_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4d, 0xcd);
    return (void *)Ov022_ArmDecoder;
}
