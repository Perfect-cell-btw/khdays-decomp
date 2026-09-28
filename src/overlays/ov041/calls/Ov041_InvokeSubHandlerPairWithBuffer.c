/* Calls two sub-handlers, passing a shared buffer pointer (this+0x84+0x2c00) and the s16 field at
 * this+0x2aba to the first, buffer only to the second. */

extern void Ov041_DispatchToFourSubHandlers();
extern void Ov041_UpdateSubBlocksIfEnabled();

void Ov041_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x84);
    Ov041_DispatchToFourSubHandlers(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov041_UpdateSubBlocksIfEnabled(this_, p + 0x2c00);
}
