extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov075_Boot(int a);
extern void Ov075_InitRegionRecordAndZero(int a);
extern void Ov075_AllocAndConfigureEmitter(int a);
extern void Ov075_InitGlobalRecordAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov075_stateCtorMultiInitReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov075_Boot(param);
    Ov075_InitRegionRecordAndZero(obj);
    Ov075_AllocAndConfigureEmitter(obj);
    Ov075_InitGlobalRecordAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x4c, 0xcc);
    return (void *)Ov022_ArmDecoder;
}
