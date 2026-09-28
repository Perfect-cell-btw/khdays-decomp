extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov060_BuildRigObject(int a);
extern void Ov060_ResetAndBindFourSlotSets(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov060_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov060_BuildRigObject(param);
    Ov060_ResetAndBindFourSlotSets(obj);
    Ov022_RequestVoiceIds(obj, 0x54, 0xd7);
    return (void *)Ov022_ArmDecoder;
}
