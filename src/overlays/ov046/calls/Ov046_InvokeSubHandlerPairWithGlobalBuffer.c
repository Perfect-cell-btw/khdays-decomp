/* Calls two sub-handlers passing a shared buffer pointer (*data_ov046_020b4b40 + 0x2c80) and the
 * s16 field at this+0x2aba to the first, buffer only to the second. */

extern int data_ov046_020b4b40;
extern void Ov046_UpdateSlotsAndFlagLocal();
extern void Ov046_InitAndProcessSixSlotsIfFlagSet();

void Ov046_InvokeSubHandlerPairWithGlobalBuffer(int this_) {
    char *p = (char *)data_ov046_020b4b40;
    Ov046_UpdateSlotsAndFlagLocal(this_, (int)(p + 0x2c80), *(short *)(this_ + 0x2aba));
    Ov046_InitAndProcessSixSlotsIfFlagSet(this_, (int)(p + 0x2c80));
}
