extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov080_BuildRigObject(int a);
extern void Ov080_ResetAndBindFourSlotSets(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov080_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov080_BuildRigObject(param);
    Ov080_ResetAndBindFourSlotSets(obj);
    Ov022_RequestVoiceIds(obj, 0x54, 0xd7);
    return (void *)Ov022_ArmDecoder;
}
