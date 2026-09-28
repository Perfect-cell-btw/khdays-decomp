extern int NNSi_FndGetCurrentRootHeap();extern void Ov037_Boot();extern void Ov037_InitEffectSlotsAlt();extern void Ov022_RequestVoiceIds();extern void Ov022_ArmDecoder(void);
int Ov037_CreateTaggedObjectHandler46Cf(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov037_Boot(p);
    Ov037_InitEffectSlotsAlt(r);
    Ov022_RequestVoiceIds(r, 0x46, 0xcf);
    return (int)Ov022_ArmDecoder;
}
