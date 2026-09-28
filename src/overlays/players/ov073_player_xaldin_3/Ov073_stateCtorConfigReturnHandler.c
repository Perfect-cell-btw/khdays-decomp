extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov073_Boot(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov073_initSubObjectSlots(int a);
extern void Ov022_ArmDecoder(void);
void *Ov073_stateCtorConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    *(int *)(obj + 0x2e1c) = 0;
    Ov073_Boot(param);
    Ov022_RequestVoiceIds(obj, 0x45, 0xc6);
    Ov073_initSubObjectSlots(obj);
    return (void *)Ov022_ArmDecoder;
}
