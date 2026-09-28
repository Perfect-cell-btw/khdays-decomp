extern int data_ov102_020bb920;
extern void Ov102_TickChargeState();
extern void Ov102_DrawNodeIfEnabled();

void Ov102_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov102_020bb920 + 0xc50);
    Ov102_TickChargeState(this_, (int)(p + 0x2000), *(short *)(this_ + 0x2aba));
    Ov102_DrawNodeIfEnabled(this_, (int)(p + 0x2000));
}
