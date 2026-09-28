extern int data_ov062_020b80e0;
extern void Ov062_NodeRequestTick();
extern void Ov062_RelaySlotEvent();

void Ov062_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov062_020b80e0 + 0x138);
    Ov062_NodeRequestTick(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov062_RelaySlotEvent(this_, (int)(p + 0x2c00));
}
