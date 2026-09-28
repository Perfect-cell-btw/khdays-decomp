/* Calls two sub-handlers passing a shared buffer pointer (*data_ov087_020b9be0 + 0xfc + 0x2c00) and
 * the s16 field at this+0x2aba to the first, buffer only to the second. */

extern char *data_ov087_020b9be0;
extern void Ov087_StepEffectSlot(void *a, void *arg1, int arg2);
extern void Ov087_PlaceTrailMarker(void *a, void *arg1);

void Ov087_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov087_020b9be0 + 0xfc;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov087_StepEffectSlot(a, arg1, arg2);
    Ov087_PlaceTrailMarker(a, arg1);
}
