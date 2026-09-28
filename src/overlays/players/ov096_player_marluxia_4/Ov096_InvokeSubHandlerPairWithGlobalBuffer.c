/* Calls two sub-handlers passing a shared buffer pointer (*data_ov096_020bc0c0 + 0xc50 + 0x2000)
 * and the s16 field at this+0x2aba to the first, buffer only to the second. */

extern char *data_ov096_020bc0c0;
extern void Ov096_ForwardToThreeSubHandlers(void *a, void *arg1, int arg2);
extern void Ov096_ForwardToThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov096_InvokeSubHandlerPairWithGlobalBuffer(char *a) {
    char *base = data_ov096_020bc0c0 + 0xc50;
    char *arg1 = base + 0x2000;
    int arg2 = *(short *)(a + 0x2aba);
    Ov096_ForwardToThreeSubHandlers(a, arg1, arg2);
    Ov096_ForwardToThreeSubHandlersIfFlagSet(a, arg1);
}
