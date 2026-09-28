extern char *data_ov094_020bc240;
extern void Ov094_UpdateAllPartsAndFlagLocal(void *a, void *arg1, int arg2);
extern void Ov094_UpdatePartsIfEnabled(void *a, void *arg1);

void Ov094_StepAttackSlotAndForward(char *a) {
    char *base = data_ov094_020bc240 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov094_UpdateAllPartsAndFlagLocal(a, arg1, arg2);
    Ov094_UpdatePartsIfEnabled(a, arg1);
}
