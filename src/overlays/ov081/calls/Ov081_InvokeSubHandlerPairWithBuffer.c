extern void Ov081_UpdateSlotsWithGate();
extern void Ov081_InvokeHandlerFor7SubObjects();

void Ov081_InvokeSubHandlerPairWithBuffer(int this_) {
    char *p = (char *)(this_ + 0x2c);
    Ov081_UpdateSlotsWithGate(this_, p + 0x2c00, *(short *)(this_ + 0x2aba));
    Ov081_InvokeHandlerFor7SubObjects(this_, p + 0x2c00);
}
