extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov090_Boot(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov090_initSubObjectSlots(int a);
extern void Ov022_ArmDecoder(void);
void *Ov090_stateCtorConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    *(int *)(obj + 0x2e1c) = 0;
    Ov090_Boot(param);
    Ov022_RequestVoiceIds(obj, 0x45, 0xc6);
    Ov090_initSubObjectSlots(obj);
    return (void *)Ov022_ArmDecoder;
}
