extern char *data_ov093_020bc3c0;
extern void Ov093_StepAttackSlot(void *a, void *arg1, int arg2);
extern void Ov093_ForwardArg1IfFlagSet(void *a, void *arg1);

void Ov093_StepAttackSlotAndForward(char *a) {
    char *base = data_ov093_020bc3c0 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov093_StepAttackSlot(a, arg1, arg2);
    Ov093_ForwardArg1IfFlagSet(a, arg1);
}
