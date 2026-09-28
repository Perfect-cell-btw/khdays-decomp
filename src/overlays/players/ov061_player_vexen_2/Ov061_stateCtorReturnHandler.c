/* Character constructor: builds the rig object, requests its two voice ids, resets its effect
 * sequence slots and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov061_BuildRigObject(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov061_ResetSequenceSlots(int a);
extern void Ov022_ArmDecoder(void);
void *Ov061_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov061_BuildRigObject(param);
    Ov022_RequestVoiceIds(obj, 0x4e, 0xc7);
    Ov061_ResetSequenceSlots(obj);
    return (void *)Ov022_ArmDecoder;
}
