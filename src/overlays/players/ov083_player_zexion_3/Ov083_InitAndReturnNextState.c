/* Character constructor: boots the character, initialises its effect record, requests its two voice
 * ids and returns the decoder step. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov083_Boot(void *obj);
extern void Ov083_InitActorTwoRegionsAndForward(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int x, int y);
extern void Ov022_ArmDecoder(void);

int Ov083_InitAndReturnNextState(void *obj) {
    void *h = NNSi_FndGetCurrentRootHeap();
    Ov083_Boot(obj);
    Ov083_InitActorTwoRegionsAndForward(h);
    Ov022_RequestVoiceIds(h, 0x4a, 0xc9);
    return (int)Ov022_ArmDecoder;
}
