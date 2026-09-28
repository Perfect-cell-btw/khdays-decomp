/* Character constructor: builds the rig object, initialises the effect slots unless in the mode
 * that has none, requests its two voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov054_BuildRigObject(int a);
extern int LoadGlobalU16At0(void);
extern void Ov054_InitEffectSlotsWithTimings(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov054_stateCtorCondConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov054_BuildRigObject(param);
    if (LoadGlobalU16At0() != 0x2a)
        Ov054_InitEffectSlotsWithTimings(obj);
    Ov022_RequestVoiceIds(obj, 0x47, 0xd3);
    return (void *)Ov022_ArmDecoder;
}
