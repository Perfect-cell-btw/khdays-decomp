extern char *data_ov073_020ba540;
extern void Ov073_DriveGuardSequence(void *a, void *arg1, int arg2);
extern void Ov073_PickSourcePosAndDraw(void *a, void *arg1);

void Ov073_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov073_020ba540 + 0xe4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov073_DriveGuardSequence(a, arg1, arg2);
    Ov073_PickSourcePosAndDraw(a, arg1);
}
