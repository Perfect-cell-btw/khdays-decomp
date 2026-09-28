/* Character constructor: builds the rig object, initialises its effect sequences, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov097_BuildRigObject(int a);
extern void Ov097_ResetAndBindFourSlotSets(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov097_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov097_BuildRigObject(param);
    Ov097_ResetAndBindFourSlotSets(obj);
    Ov022_RequestVoiceIds(obj, 0x54, 0xd7);
    return (void *)Ov022_ArmDecoder;
}
