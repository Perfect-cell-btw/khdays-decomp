/* Calls Ov078_TickChargeStateGated(this, arg1+0x18+i*0x10c, arg2) for i in 0..1, then
 * Ov078_StepStoredShot(this, arg1+0x308, arg2). */

extern void Ov078_TickChargeStateGated();
extern void Ov078_StepStoredShot();

void Ov078_ProcessTwoSlotsThenTail(int this_, int arg1, int arg2) {
    int i;
    char *p = (char *)(arg1 + 0x18);
    for (i = 0; i < 2; i++, p += 0x10c) {
        Ov078_TickChargeStateGated(this_, (int)p, arg2);
    }
    Ov078_StepStoredShot(this_, arg1 + 0x308, arg2);
}
