/* Character constructor: clears its effect state, boots the character, requests its two voice ids,
 * initialises its effect block and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov034_Boot(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov034_initSubObjectSlots(int a);
extern void Ov022_ArmDecoder(void);
void *Ov034_stateCtorConfigReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    *(int *)(obj + 0x2e1c) = 0;
    Ov034_Boot(param);
    Ov022_RequestVoiceIds(obj, 0x45, 0xc6);
    Ov034_initSubObjectSlots(obj);
    return (void *)Ov022_ArmDecoder;
}
