extern char *data_ov059_020b7320;
extern void Ov059_ForwardToThreeSubHandlers(void *a, void *arg1, int arg2);
extern void Ov059_ForwardToThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov059_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov059_020b7320 + 0xc50;
    char *arg1 = base + 0x2000;
    int arg2 = *(short *)(a + 0x2aba);
    Ov059_ForwardToThreeSubHandlers(a, arg1, arg2);
    Ov059_ForwardToThreeSubHandlersIfFlagSet(a, arg1);
}
