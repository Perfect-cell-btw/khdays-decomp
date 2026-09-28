extern void Ov095_TickChargeStateGated();
extern void Ov095_StepStoredShot();

void Ov095_ProcessTwoSlotsThenTail(int this_, int arg1, int arg2) {
    int i;
    char *p = (char *)(arg1 + 0x18);
    for (i = 0; i < 2; i++, p += 0x10c) {
        Ov095_TickChargeStateGated(this_, (int)p, arg2);
    }
    Ov095_StepStoredShot(this_, arg1 + 0x308, arg2);
}
