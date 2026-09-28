extern void Ov097_DispatchToFourSubHandlers();
extern void Ov097_UpdateSubBlocksIfEnabled();

void Ov097_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x84);
    Ov097_DispatchToFourSubHandlers(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov097_UpdateSubBlocksIfEnabled(this_, p + 0x2c00);
}
