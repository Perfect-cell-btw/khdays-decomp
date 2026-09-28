extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov076_Boot(int param);
extern void Ov076_InitEffectSlotsAlt(int obj);
extern void Ov022_RequestVoiceIds(int obj, int tag_a, int tag_b);
extern void Ov022_ArmDecoder(void);

void *Ov076_CreateTaggedObjectHandler46Cf(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov076_Boot(param);
    Ov076_InitEffectSlotsAlt(obj);
    Ov022_RequestVoiceIds(obj, 0x46, 0xcf);
    return (void *)Ov022_ArmDecoder;
}
