extern void Ov042_UpdateSlotsWithGate();
extern void Ov042_InvokeHandlerFor7SubObjects();

void Ov042_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x2c);
    Ov042_UpdateSlotsWithGate(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov042_InvokeHandlerFor7SubObjects(this_, p + 0x2c00);
}
