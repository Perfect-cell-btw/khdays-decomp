extern int NNSi_FndGetCurrentRootHeap();extern void Ov038_BuildRigObject();extern void Ov038_ResetSequences();extern void Ov022_RequestVoiceIds();extern void Ov022_ArmDecoder(void);
int Ov038_initSubitemsClear(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov038_BuildRigObject(p);
    Ov038_ResetSequences(r);
    Ov022_RequestVoiceIds(r, 0x49, 0xc8);
    return (int)Ov022_ArmDecoder;
}
