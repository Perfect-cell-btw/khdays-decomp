extern int data_ov047_020b4380;
extern void Ov047_TickChargeState();
extern void Ov047_DrawNodeIfEnabled();

void Ov047_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov047_020b4380 + 0xc50);
    Ov047_TickChargeState(this_, (int)(p + 0x2000), *(short *)(this_ + 0x2aba));
    Ov047_DrawNodeIfEnabled(this_, (int)(p + 0x2000));
}
