/* For the two records at param_2[5] and param_2[6], forward any that is not -1 to
 * Slot_SetMode2Bit together with param_1 and param_3. */
extern void Slot_SetMode2Bit(int a, int b, int c);

void Ov008_ReleaseTwoSlotsEx_2(int param_1, int param_2, int param_3) {
    int i;
    for (i = 0; i < 2; i++) {
        int v = ((int *)param_2)[i + 5];
        if (v != -1) {
            Slot_SetMode2Bit(param_1, v, param_3);
        }
    }
}
