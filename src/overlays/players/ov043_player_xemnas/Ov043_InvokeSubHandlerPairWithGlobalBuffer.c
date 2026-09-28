extern int data_ov043_020b58e0;
extern void Ov043_NodeRequestTick();
extern void Ov043_RelaySlotEvent();

void Ov043_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov043_020b58e0 + 0x138);
    Ov043_NodeRequestTick(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov043_RelaySlotEvent(this_, (int)(p + 0x2c00));
}
