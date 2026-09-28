/* Class pfnCtor: builds the actor, requests voice ids 0x44/0xca, runs its init and returns the
 * decoder step. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov033_Boot();
extern void Ov022_RequestVoiceIds();
extern void Ov033_initSubObjectSlots();
extern void Ov022_ArmDecoder();

void *Ov033_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov033_Boot(a);
    Ov022_RequestVoiceIds(r, 0x44, 0xca);
    Ov033_initSubObjectSlots(r);
    return (void *)Ov022_ArmDecoder;
}
