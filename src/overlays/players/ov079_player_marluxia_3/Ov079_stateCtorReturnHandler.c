extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov079_BuildRigObject(int a);
extern void Ov079_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov079_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov079_BuildRigObject(param);
    Ov079_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4b, 0xce);
    return (void *)Ov022_ArmDecoder;
}
