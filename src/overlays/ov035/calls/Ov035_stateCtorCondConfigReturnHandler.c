extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov035_BuildRigObject(int a);
extern int LoadGlobalU16At0(void);
extern void Ov035_InitEffectSlotsWithTimings(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov035_stateCtorCondConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov035_BuildRigObject(param);
    if (LoadGlobalU16At0() != 0x2a)
        Ov035_InitEffectSlotsWithTimings(obj);
    Ov022_RequestVoiceIds(obj, 0x47, 0xd3);
    return (void *)Ov022_ArmDecoder;
}
