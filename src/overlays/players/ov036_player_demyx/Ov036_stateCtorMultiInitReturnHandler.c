/* Character constructor: boots the character, initialises its charge record, allocates its effect
 * emitter and secondary effects, requests its two voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov036_Boot(int a);
extern void Ov036_InitRegionRecordAndZero(int a);
extern void Ov036_AllocAndConfigureEmitter(int a);
extern void Ov036_InitGlobalRecordAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov036_stateCtorMultiInitReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov036_Boot(param);
    Ov036_InitRegionRecordAndZero(obj);
    Ov036_AllocAndConfigureEmitter(obj);
    Ov036_InitGlobalRecordAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x4c, 0xcc);
    return (void *)Ov022_ArmDecoder;
}
