extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov085_PanelCtor(int a);
extern void Ov085_InitTwoGlobalRegionsAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov085_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov085_PanelCtor(param);
    Ov085_InitTwoGlobalRegionsAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x52, 0xd4);
    return (void *)Ov022_ArmDecoder;
}
