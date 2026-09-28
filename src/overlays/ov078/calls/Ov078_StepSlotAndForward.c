extern char *data_ov078_020ba4e0;
extern void Ov078_ProcessTwoSlotsThenTail(void *a, void *arg1, int arg2);
extern void Ov078_ProcessTwoSlotsIfFlagSet(void *a, void *arg1);

void Ov078_StepSlotAndForward(char *a) {
    char *base = data_ov078_020ba4e0 + 0xd4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov078_ProcessTwoSlotsThenTail(a, arg1, arg2);
    Ov078_ProcessTwoSlotsIfFlagSet(a, arg1);
}
