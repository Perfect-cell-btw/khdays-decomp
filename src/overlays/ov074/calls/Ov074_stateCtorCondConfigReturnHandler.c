extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov074_BuildRigObject(int a);
extern int LoadGlobalU16At0(void);
extern void Ov074_InitEffectSlotsWithTimings(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov074_stateCtorCondConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov074_BuildRigObject(param);
    if (LoadGlobalU16At0() != 0x2a)
        Ov074_InitEffectSlotsWithTimings(obj);
    Ov022_RequestVoiceIds(obj, 0x47, 0xd3);
    return (void *)Ov022_ArmDecoder;
}
