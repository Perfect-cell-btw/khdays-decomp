extern void Ov039_TickChargeStateGated();
extern void Ov039_StepStoredShot();

void Ov039_ProcessTwoSlotsThenTail(int this_, int arg1, int arg2) {
    int i;
    char *p = (char *)(arg1 + 0x18);
    for (i = 0; i < 2; i++, p += 0x10c) {
        Ov039_TickChargeStateGated(this_, (int)p, arg2);
    }
    Ov039_StepStoredShot(this_, arg1 + 0x308, arg2);
}
