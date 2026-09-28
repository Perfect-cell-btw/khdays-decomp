extern char *data_ov077_020b9b80;
extern void Ov077_UpdateAllPartsAndFlagLocal(void *a, void *arg1, int arg2);
extern void Ov077_UpdatePartsIfEnabled(void *a, void *arg1);

void Ov077_StepAttackSlotAndForward(char *a) {
    char *base = data_ov077_020b9b80 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov077_UpdateAllPartsAndFlagLocal(a, arg1, arg2);
    Ov077_UpdatePartsIfEnabled(a, arg1);
}
