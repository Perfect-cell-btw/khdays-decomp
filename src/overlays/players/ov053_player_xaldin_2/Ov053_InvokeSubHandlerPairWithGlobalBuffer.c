/* Calls two sub-handlers passing a shared buffer pointer (*data_ov053_020b7e60+0xe4+0x2c00) and the
 * animation step at this+0x2aba to the first, buffer only to the second. */

extern int data_ov053_020b7e60;
extern void Ov053_DriveGuardSequence();
extern void Ov053_PickSourcePosAndDraw();

void Ov053_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov053_020b7e60 + 0xe4);
    Ov053_DriveGuardSequence(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov053_PickSourcePosAndDraw(this_, (int)(p + 0x2c00));
}
