extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov070_ActorCtor();
extern void Ov022_RequestVoiceIds();
extern void Ov070_initTwoEntrySlots();
extern void Ov022_ArmDecoder();

void *Ov070_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov070_ActorCtor(a);
    Ov022_RequestVoiceIds(r, 0x42, 0xcb);
    Ov070_initTwoEntrySlots(r);
    return (void *)Ov022_ArmDecoder;
}
