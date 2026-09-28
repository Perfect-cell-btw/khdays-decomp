extern int data_ov065_020b7340;
extern void Ov065_UpdateSlotsAndFlagLocal();
extern void Ov065_InitAndProcessSixSlotsIfFlagSet();

void Ov065_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)data_ov065_020b7340;
    Ov065_UpdateSlotsAndFlagLocal(this_, (int)(p + 0x2c80), *(short *)(this_ + 0x2aba));
    Ov065_InitAndProcessSixSlotsIfFlagSet(this_, (int)(p + 0x2c80));
}
