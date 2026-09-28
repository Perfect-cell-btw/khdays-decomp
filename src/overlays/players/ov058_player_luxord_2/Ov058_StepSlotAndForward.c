/* Steps the table slot (+0x2cd4) with the object's slot index, then forwards it. */

extern char *data_ov058_020b7e00;
extern void Ov058_ProcessTwoSlotsThenTail(void *a, void *arg1, int arg2);
extern void Ov058_ProcessTwoSlotsIfFlagSet(void *a, void *arg1);

void Ov058_StepSlotAndForward(char *a) {
    char *base = data_ov058_020b7e00 + 0xd4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov058_ProcessTwoSlotsThenTail(a, arg1, arg2);
    Ov058_ProcessTwoSlotsIfFlagSet(a, arg1);
}
