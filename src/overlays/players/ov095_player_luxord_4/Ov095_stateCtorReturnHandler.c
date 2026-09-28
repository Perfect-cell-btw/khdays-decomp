extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov095_Boot(int a);
extern void Ov095_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov095_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov095_Boot(param);
    Ov095_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4d, 0xcd);
    return (void *)Ov022_ArmDecoder;
}
