/* Calls Ov058_TickChargeStateGated(this, arg1+0x18+i*0x10c, arg2) for i in 0..1, then
 * Ov058_StepStoredShot(this, arg1+0x308, arg2). */

extern void Ov058_TickChargeStateGated();
extern void Ov058_StepStoredShot();

void Ov058_ProcessTwoSlotsThenTail(int this_, int arg1, int arg2) {
    int i;
    char *p = (char *)(arg1 + 0x18);
    for (i = 0; i < 2; i++, p += 0x10c) {
        Ov058_TickChargeStateGated(this_, (int)p, arg2);
    }
    Ov058_StepStoredShot(this_, arg1 + 0x308, arg2);
}
