extern int data_ov101_020bc0e0;
extern void Ov101_UpdateSlotsAndFlagLocal();
extern void Ov101_InitAndProcessSixSlotsIfFlagSet();

void Ov101_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)data_ov101_020bc0e0;
    Ov101_UpdateSlotsAndFlagLocal(this_, (int)(p + 0x2c80), *(short *)(this_ + 0x2aba));
    Ov101_InitAndProcessSixSlotsIfFlagSet(this_, (int)(p + 0x2c80));
}
