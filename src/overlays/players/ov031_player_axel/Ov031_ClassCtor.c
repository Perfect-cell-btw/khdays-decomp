/* Class pfnCtor: builds the actor, requests voice ids 0x42/0xcb, runs its init and returns the
 * decoder step. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov031_ActorCtor();
extern void Ov022_RequestVoiceIds();
extern void Ov031_initTwoEntrySlots();
extern void Ov022_ArmDecoder();

void *Ov031_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov031_ActorCtor(a);
    Ov022_RequestVoiceIds(r, 0x42, 0xcb);
    Ov031_initTwoEntrySlots(r);
    return (void *)Ov022_ArmDecoder;
}
