/* Sets bit 1 on the object's two slots that are in use. */

extern void Slot_SetFlagBit1(int arg0, int arg1);

void Ov008_ReleaseTwoSlots_2(int arg0, void *object)
{
    int i;

    for (i = 0; i < 2; i++) {
        int value = ((int *)object)[i + 5];

        if (value != -1) {
            Slot_SetFlagBit1(arg0, value);
        }
    }
}
