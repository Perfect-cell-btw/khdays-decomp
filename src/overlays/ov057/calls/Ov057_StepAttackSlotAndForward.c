extern char *data_ov057_020b74a0;
extern void Ov057_UpdateAllPartsAndFlagLocal(void *a, void *arg1, int arg2);
extern void Ov057_UpdatePartsIfEnabled(void *a, void *arg1);

void Ov057_StepAttackSlotAndForward(char *a) {
    char *base = data_ov057_020b74a0 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov057_UpdateAllPartsAndFlagLocal(a, arg1, arg2);
    Ov057_UpdatePartsIfEnabled(a, arg1);
}
