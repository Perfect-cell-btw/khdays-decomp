/* Class pfnCtor: builds the actor, requests voice ids 0x44/0xca, runs its init and returns the
 * decoder step. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov051_Boot();
extern void Ov022_RequestVoiceIds();
extern void Ov051_initSubObjectSlots();
extern void Ov022_ArmDecoder();

void *Ov051_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov051_Boot(a);
    Ov022_RequestVoiceIds(r, 0x44, 0xca);
    Ov051_initSubObjectSlots(r);
    return (void *)Ov022_ArmDecoder;
}
