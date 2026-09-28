extern int data_ov049_020b4d00;
extern void Ov049_StepEffectSlot();
extern void Ov049_PlaceTrailMarker();

void Ov049_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov049_020b4d00 + 0xfc);
    Ov049_StepEffectSlot(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov049_PlaceTrailMarker(this_, (int)(p + 0x2c00));
}
