/* Class pfnCtor: builds the actor, requests voice ids 0x44/0xca, runs its init and returns the
 * decoder step. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov089_Boot();
extern void Ov022_RequestVoiceIds();
extern void Ov089_initSubObjectSlots();
extern void Ov022_ArmDecoder();

void *Ov089_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov089_Boot(a);
    Ov022_RequestVoiceIds(r, 0x44, 0xca);
    Ov089_initSubObjectSlots(r);
    return (void *)Ov022_ArmDecoder;
}
