extern int data_ov085_020b9260;
extern void Ov085_TickChargeState();
extern void Ov085_DrawNodeIfEnabled();

void Ov085_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov085_020b9260 + 0xc50);
    Ov085_TickChargeState(this_, (int)(p + 0x2000), *(short *)(this_ + 0x2aba));
    Ov085_DrawNodeIfEnabled(this_, (int)(p + 0x2000));
}
