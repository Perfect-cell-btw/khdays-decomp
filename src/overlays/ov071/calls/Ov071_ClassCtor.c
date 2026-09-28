extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov071_Boot();
extern void Ov022_RequestVoiceIds();
extern void Ov071_initSubObjectSlots();
extern void Ov022_ArmDecoder();

void *Ov071_ClassCtor(void *a)
{
    void *r = NNSi_FndGetCurrentRootHeap();
    Ov071_Boot(a);
    Ov022_RequestVoiceIds(r, 0x44, 0xca);
    Ov071_initSubObjectSlots(r);
    return (void *)Ov022_ArmDecoder;
}
