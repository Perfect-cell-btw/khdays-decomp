/* Calls two sub-handlers passing a shared buffer pointer (*globalData+0xe4+0x2c00) and the s16
 * field at this+0x2aba to the first, buffer only to the second. */

extern char *data_ov090_020bcc00;
extern void Ov090_DriveGuardSequence(void *a, void *arg1, int arg2);
extern void Ov090_PickSourcePosAndDraw(void *a, void *arg1);

void Ov090_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov090_020bcc00 + 0xe4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov090_DriveGuardSequence(a, arg1, arg2);
    Ov090_PickSourcePosAndDraw(a, arg1);
}
