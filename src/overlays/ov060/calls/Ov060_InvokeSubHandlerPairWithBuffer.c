extern void Ov060_DispatchToFourSubHandlers();
extern void Ov060_UpdateSubBlocksIfEnabled();

void Ov060_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x84);
    Ov060_DispatchToFourSubHandlers(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov060_UpdateSubBlocksIfEnabled(this_, p + 0x2c00);
}
