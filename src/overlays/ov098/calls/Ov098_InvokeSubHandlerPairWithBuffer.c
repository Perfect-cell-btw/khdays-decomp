extern void Ov098_UpdateSlotsWithGate();
extern void Ov098_InvokeHandlerFor7SubObjects();

void Ov098_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x2c);
    Ov098_UpdateSlotsWithGate(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov098_InvokeHandlerFor7SubObjects(this_, p + 0x2c00);
}
