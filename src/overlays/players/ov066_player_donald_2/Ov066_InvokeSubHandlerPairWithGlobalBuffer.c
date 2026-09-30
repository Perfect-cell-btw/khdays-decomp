/* Calls two sub-handlers passing a shared buffer pointer (*globalData + 0xc50 + 0x2000) and the s16
 * animation step at this+0x2aba to the first, buffer only to the second. */

extern int data_ov066_020b6b80;
extern void Ov066_TickChargeState();
extern void Ov066_DrawNodeIfEnabled();

void Ov066_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov066_020b6b80 + 0xc50);
    Ov066_TickChargeState(this_, (int)(p + 0x2000), *(short *)(this_ + 0x2aba));
    Ov066_DrawNodeIfEnabled(this_, (int)(p + 0x2000));
}
