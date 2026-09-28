extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov066_PanelCtor(int a);
extern void Ov066_InitTwoGlobalRegionsAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov066_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov066_PanelCtor(param);
    Ov066_InitTwoGlobalRegionsAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x52, 0xd4);
    return (void *)Ov022_ArmDecoder;
}
