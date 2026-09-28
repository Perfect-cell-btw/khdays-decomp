extern char *data_ov076_020b9d00;
extern void Ov076_StepAttackSlot(void *a, void *arg1, int arg2);
extern void Ov076_ForwardArg1IfFlagSet(void *a, void *arg1);

void Ov076_StepAttackSlotAndForward(char *a) {
    char *base = data_ov076_020b9d00 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov076_StepAttackSlot(a, arg1, arg2);
    Ov076_ForwardArg1IfFlagSet(a, arg1);
}
