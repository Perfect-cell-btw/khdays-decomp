/* Class pfnCtor: builds the actor, requests voice ids 0x42/0xcb, runs its init and returns the
 * decoder step. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov088_ActorCtor();
extern void Ov022_RequestVoiceIds();
extern void Ov088_initTwoEntrySlots();
extern void Ov022_ArmDecoder();

void *Ov088_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov088_ActorCtor(a);
    Ov022_RequestVoiceIds(r, 0x42, 0xcb);
    Ov088_initTwoEntrySlots(r);
    return (void *)Ov022_ArmDecoder;
}
