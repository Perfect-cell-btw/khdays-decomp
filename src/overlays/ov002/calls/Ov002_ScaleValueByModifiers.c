/* Scale the Q12 value by the two modifiers the object carries: property 0x56
 * contributes a proportional bonus (0x19a per point) and property 0x57 doubles
 * the result. Rounds up on the way back out of Q12. Values that start at or
 * below zero are returned untouched. */
extern int Slot_EvalPackedParam(void *self, int prop);
extern int FX_Mul(int value, int scale);

int Ov002_ScaleValueByModifiers(void *self, int value) {
    int q = value << 0xc;

    if (q > 0) {
        int bonus = Slot_EvalPackedParam(self, 0x56);

        if (bonus > 0) {
            q += FX_Mul(q, bonus * 0x19a);
        }
        if (Slot_EvalPackedParam(self, 0x57) != 0) {
            q <<= 1;
        }
        q += 0xfff;
    }

    return q >> 0xc;
}
