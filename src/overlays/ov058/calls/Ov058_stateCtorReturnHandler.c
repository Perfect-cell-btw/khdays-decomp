extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov058_Boot(int a);
extern void Ov058_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov058_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov058_Boot(param);
    Ov058_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4d, 0xcd);
    return (void *)Ov022_ArmDecoder;
}
