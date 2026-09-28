extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov041_BuildRigObject(int a);
extern void Ov041_ResetAndBindFourSlotSets(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov041_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov041_BuildRigObject(param);
    Ov041_ResetAndBindFourSlotSets(obj);
    Ov022_RequestVoiceIds(obj, 0x54, 0xd7);
    return (void *)Ov022_ArmDecoder;
}
