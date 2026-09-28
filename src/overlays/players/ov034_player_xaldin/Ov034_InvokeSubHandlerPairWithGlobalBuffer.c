/* Calls two sub-handlers passing a shared buffer pointer (*globalData+0xe4+0x2c00) and the s16
 * field at this+0x2aba to the first, buffer only to the second. */

extern int data_ov034_020b5660;
extern void Ov034_DriveGuardSequence();
extern void Ov034_PickSourcePosAndDraw();

void Ov034_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)(data_ov034_020b5660 + 0xe4);
    Ov034_DriveGuardSequence(this_, (int)(p + 0x2c00), *(short *)(this_ + 0x2aba));
    Ov034_PickSourcePosAndDraw(this_, (int)(p + 0x2c00));
}
