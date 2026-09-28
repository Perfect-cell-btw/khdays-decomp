extern char *data_ov104_020bc2a0;
extern void Ov104_StepEffectSlot(void *a, void *arg1, int arg2);
extern void Ov104_PlaceTrailMarker(void *a, void *arg1);

void Ov104_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov104_020bc2a0 + 0xfc;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov104_StepEffectSlot(a, arg1, arg2);
    Ov104_PlaceTrailMarker(a, arg1);
}
