/* Sets the Q12 screen position of BOTH slots that make up one selection entry. An entry holds two
 * slot ids at +0x14 and +0x18; -1 means the slot is unused. This walks those two and calls
 * Slot_SetPosition(object, slotId, pos) for each valid one, so a single call moves the whole entry.
 * Was named Ov000_ReleaseTwoSlotsEx, which is wrong on both counts -- it releases nothing. Paired
 * with Ov000_GetEntryPosition (Ov000_GetEntryPosition), which reads back the position of the
 * entry's first valid slot. */

extern int Slot_SetPosition();

void Ov000_SetEntryPosition(int a, int *b, int c) {
    int i;
    for (i = 0; i < 2; i++) {
        int v = b[i + 5];
        if (v != -1) {
            Slot_SetPosition(a, v, c);
        }
    }
}
