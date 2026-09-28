/* Character constructor: boots the character, initialises its three effect slots, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov048_Boot(int a);
extern void Ov048_InitThreeEffectSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov048_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov048_Boot(param);
    Ov048_InitThreeEffectSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x53, 0xd5);
    return (void *)Ov022_ArmDecoder;
}
