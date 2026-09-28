extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov065_BuildRigObject(int a);
extern void Ov065_ResetAndBindSlotArray(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov065_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov065_BuildRigObject(param);
    Ov065_ResetAndBindSlotArray(obj);
    Ov022_RequestVoiceIds(obj, 0x48, 0xd6);
    return (void *)Ov022_ArmDecoder;
}
