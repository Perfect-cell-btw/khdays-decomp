extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov050_ActorCtor();
extern void Ov022_RequestVoiceIds();
extern void Ov050_initTwoEntrySlots();
extern void Ov022_ArmDecoder();

void *Ov050_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov050_ActorCtor(a);
    Ov022_RequestVoiceIds(r, 0x42, 0xcb);
    Ov050_initTwoEntrySlots(r);
    return (void *)Ov022_ArmDecoder;
}
