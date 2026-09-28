extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov046_BuildRigObject(int a);
extern void Ov046_ResetAndBindSlotArray(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov046_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov046_BuildRigObject(param);
    Ov046_ResetAndBindSlotArray(obj);
    Ov022_RequestVoiceIds(obj, 0x48, 0xd6);
    return (void *)Ov022_ArmDecoder;
}
