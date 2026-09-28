extern char *data_ov048_020b4b80;
extern void Ov048_ForwardToThreeSubHandlersSameArgs(void *a, void *arg1, int arg2);
extern void Ov048_RunThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov048_StepAttackSlotAndForward(char *a) {
    char *base = data_ov048_020b4b80 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov048_ForwardToThreeSubHandlersSameArgs(a, arg1, arg2);
    Ov048_RunThreeSubHandlersIfFlagSet(a, arg1);
}
