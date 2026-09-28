extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov059_BuildRigObject(int a);
extern void Ov059_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov059_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov059_BuildRigObject(param);
    Ov059_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4b, 0xce);
    return (void *)Ov022_ArmDecoder;
}
