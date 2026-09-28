extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov067_Boot(int a);
extern void Ov067_InitThreeEffectSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov067_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov067_Boot(param);
    Ov067_InitThreeEffectSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x53, 0xd5);
    return (void *)Ov022_ArmDecoder;
}
