extern char *data_ov056_020b7620;
extern void Ov056_StepAttackSlot(void *a, void *arg1, int arg2);
extern void Ov056_ForwardArg1IfFlagSet(void *a, void *arg1);

void Ov056_StepAttackSlotAndForward(char *a) {
    char *base = data_ov056_020b7620 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov056_StepAttackSlot(a, arg1, arg2);
    Ov056_ForwardArg1IfFlagSet(a, arg1);
}
