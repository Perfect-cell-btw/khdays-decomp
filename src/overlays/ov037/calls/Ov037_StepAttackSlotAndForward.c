/* Steps the attack slot of the table (+0x2c2c) with the object's slot index, then forwards it. */

extern char *data_ov037_020b4e20;
extern void Ov037_StepAttackSlot(void *a, void *arg1, int arg2);
extern void Ov037_ForwardArg1IfFlagSet(void *a, void *arg1);

void Ov037_StepAttackSlotAndForward(char *a) {
    char *base = data_ov037_020b4e20 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov037_StepAttackSlot(a, arg1, arg2);
    Ov037_ForwardArg1IfFlagSet(a, arg1);
}
