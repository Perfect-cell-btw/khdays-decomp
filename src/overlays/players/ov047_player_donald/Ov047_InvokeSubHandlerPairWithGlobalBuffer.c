/* Calls two sub-handlers passing a shared buffer pointer (*data_ov047_020b4380 + 0xc50 + 0x2000)
 * and the animation step at this+0x2aba to the first, buffer only to the second. */

extern int data_ov047_020b4380;
extern void Ov047_TickChargeState();
extern void Ov047_DrawNodeIfEnabled();

void Ov047_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov047_020b4380 + 0xc50);
    Ov047_TickChargeState(this_, (int)(p + 0x2000), *(short *)(this_ + 0x2aba));
    Ov047_DrawNodeIfEnabled(this_, (int)(p + 0x2000));
}
