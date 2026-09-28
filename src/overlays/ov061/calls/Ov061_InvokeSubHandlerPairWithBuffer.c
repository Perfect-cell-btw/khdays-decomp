extern void Ov061_UpdateSlotsWithGate();
extern void Ov061_InvokeHandlerFor7SubObjects();

void Ov061_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x2c);
    Ov061_UpdateSlotsWithGate(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov061_InvokeHandlerFor7SubObjects(this_, p + 0x2c00);
}
