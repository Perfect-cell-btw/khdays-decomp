extern int data_ov084_020b9a20;
extern void Ov084_UpdateSlotsAndFlagLocal();
extern void Ov084_InitAndProcessSixSlotsIfFlagSet();

void Ov084_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)data_ov084_020b9a20;
    Ov084_UpdateSlotsAndFlagLocal(this_, (int)(p + 0x2c80), *(short *)(this_ + 0x2aba));
    Ov084_InitAndProcessSixSlotsIfFlagSet(this_, (int)(p + 0x2c80));
}
