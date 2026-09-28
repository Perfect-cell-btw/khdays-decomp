/* Character constructor: builds the rig object, initialises its effect block, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov084_BuildRigObject(int a);
extern void Ov084_ResetAndBindSlotArray(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov084_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov084_BuildRigObject(param);
    Ov084_ResetAndBindSlotArray(obj);
    Ov022_RequestVoiceIds(obj, 0x48, 0xd6);
    return (void *)Ov022_ArmDecoder;
}
