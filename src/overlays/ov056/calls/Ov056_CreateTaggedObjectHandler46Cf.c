extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov056_Boot(int param);
extern void Ov056_InitEffectSlotsAlt(int obj);
extern void Ov022_RequestVoiceIds(int obj, int tag_a, int tag_b);
extern void Ov022_ArmDecoder(void);

void *Ov056_CreateTaggedObjectHandler46Cf(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov056_Boot(param);
    Ov056_InitEffectSlotsAlt(obj);
    Ov022_RequestVoiceIds(obj, 0x46, 0xcf);
    return (void *)Ov022_ArmDecoder;
}
