extern char *data_ov079_020b9a00;
extern void Ov079_ForwardToThreeSubHandlers(void *a, void *arg1, int arg2);
extern void Ov079_ForwardToThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov079_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov079_020b9a00 + 0xc50;
    char *arg1 = base + 0x2000;
    int arg2 = *(short *)(a + 0x2aba);
    Ov079_ForwardToThreeSubHandlers(a, arg1, arg2);
    Ov079_ForwardToThreeSubHandlersIfFlagSet(a, arg1);
}
