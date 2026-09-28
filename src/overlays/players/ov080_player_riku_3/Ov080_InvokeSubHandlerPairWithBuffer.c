/* Calls two sub-handlers, passing a shared buffer pointer (this+0x84+0x2c00) and the s16 field at
 * this+0x2aba to the first, buffer only to the second. */

extern void Ov080_DispatchToFourSubHandlers();
extern void Ov080_UpdateSubBlocksIfEnabled();

void Ov080_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x84);
    Ov080_DispatchToFourSubHandlers(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov080_UpdateSubBlocksIfEnabled(this_, p + 0x2c00);
}
