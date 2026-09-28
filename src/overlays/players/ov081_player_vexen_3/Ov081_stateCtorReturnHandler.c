/* Character constructor: builds the rig object, requests its two voice ids, resets its effect
 * sequence slots and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov081_BuildRigObject(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov081_ResetSequenceSlots(int a);
extern void Ov022_ArmDecoder(void);
void *Ov081_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov081_BuildRigObject(param);
    Ov022_RequestVoiceIds(obj, 0x4e, 0xc7);
    Ov081_ResetSequenceSlots(obj);
    return (void *)Ov022_ArmDecoder;
}
