extern char *data_ov086_020b9a60;
extern void Ov086_ForwardToThreeSubHandlersSameArgs(void *a, void *arg1, int arg2);
extern void Ov086_RunThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov086_StepAttackSlotAndForward(char *a) {
    char *base = data_ov086_020b9a60 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov086_ForwardToThreeSubHandlersSameArgs(a, arg1, arg2);
    Ov086_RunThreeSubHandlersIfFlagSet(a, arg1);
}
