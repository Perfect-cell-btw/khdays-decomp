/* Steps the attack slot of the table (+0x2c2c) with the object's slot index, then forwards it. */

extern char *data_ov038_020b4ca0;
extern void Ov038_UpdateAllPartsAndFlagLocal(void *a, void *arg1, int arg2);
extern void Ov038_UpdatePartsIfEnabled(void *a, void *arg1);

void Ov038_StepAttackSlotAndForward(char *a) {
    char *base = data_ov038_020b4ca0 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov038_UpdateAllPartsAndFlagLocal(a, arg1, arg2);
    Ov038_UpdatePartsIfEnabled(a, arg1);
}
