extern int data_ov068_020b7500;
extern void Ov068_StepEffectSlot();
extern void Ov068_PlaceTrailMarker();

void Ov068_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov068_020b7500 + 0xfc);
    Ov068_StepEffectSlot(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov068_PlaceTrailMarker(this_, (int)(p + 0x2c00));
}
