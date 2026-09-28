extern char *data_ov103_020bc120;
extern void Ov103_ForwardToThreeSubHandlersSameArgs(void *a, void *arg1, int arg2);
extern void Ov103_RunThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov103_StepAttackSlotAndForward(char *a) {
    char *base = data_ov103_020bc120 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov103_ForwardToThreeSubHandlersSameArgs(a, arg1, arg2);
    Ov103_RunThreeSubHandlersIfFlagSet(a, arg1);
}
