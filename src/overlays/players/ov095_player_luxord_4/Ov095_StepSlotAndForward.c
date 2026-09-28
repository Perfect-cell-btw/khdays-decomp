/* Steps the table slot (+0x2cd4) with the object's slot index, then forwards it. */

extern char *data_ov095_020bcba0;
extern void Ov095_ProcessTwoSlotsThenTail(void *a, void *arg1, int arg2);
extern void Ov095_ProcessTwoSlotsIfFlagSet(void *a, void *arg1);

void Ov095_StepSlotAndForward(char *a) {
    char *base = data_ov095_020bcba0 + 0xd4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov095_ProcessTwoSlotsThenTail(a, arg1, arg2);
    Ov095_ProcessTwoSlotsIfFlagSet(a, arg1);
}
