/* Steps the table slot (+0x2cd4) with the object's slot index, then forwards it. */

extern char *data_ov039_020b5600;
extern void Ov039_ProcessTwoSlotsThenTail(void *a, void *arg1, int arg2);
extern void Ov039_ProcessTwoSlotsIfFlagSet(void *a, void *arg1);

void Ov039_StepSlotAndForward(char *a) {
    char *base = data_ov039_020b5600 + 0xd4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov039_ProcessTwoSlotsThenTail(a, arg1, arg2);
    Ov039_ProcessTwoSlotsIfFlagSet(a, arg1);
}
