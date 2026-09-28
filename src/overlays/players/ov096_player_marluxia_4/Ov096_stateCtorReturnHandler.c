/* Character constructor: builds the rig object, sets up its effect sequence slots, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov096_BuildRigObject(int a);
extern void Ov096_SetupSequenceSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov096_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov096_BuildRigObject(param);
    Ov096_SetupSequenceSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x4b, 0xce);
    return (void *)Ov022_ArmDecoder;
}
