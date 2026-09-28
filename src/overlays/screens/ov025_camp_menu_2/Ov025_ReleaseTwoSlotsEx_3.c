/* Sets the mode bit on the object's two slots that are in use. */

extern void Slot_SetMode2Bit();

void Ov025_ReleaseTwoSlotsEx_3(int arg0, int arg1, unsigned int arg2) {
    int i = 0;
    do {
        int v = ((int *)arg1)[i + 5];
        if (v != -1) Slot_SetMode2Bit(arg0, v, arg2);
        i++;
    } while (i < 2);
}
