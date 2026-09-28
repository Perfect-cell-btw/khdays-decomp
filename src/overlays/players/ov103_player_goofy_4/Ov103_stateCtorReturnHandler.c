/* Character constructor: boots the character, initialises its three effect slots, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov103_Boot(int a);
extern void Ov103_InitThreeEffectSlots(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov103_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov103_Boot(param);
    Ov103_InitThreeEffectSlots(obj);
    Ov022_RequestVoiceIds(obj, 0x53, 0xd5);
    return (void *)Ov022_ArmDecoder;
}
