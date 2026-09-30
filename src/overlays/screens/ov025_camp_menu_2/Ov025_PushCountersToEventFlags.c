/* Ov025_PushCountersToEventFlags -- push the two menu counters into the event-flag store, ov008.
 * Writes the event context's counter fields (base+8 and base+0xc, base = *gGameState) into
 * flag groups 10 and 0x14 via Ov025_UpdateDecimalDisplay (width 8, max 0xf423f, sub-ids 0x14/0x16). */
extern void Ov025_UpdateDecimalDisplay(int group, int value, int max, int width, int subId);
extern int  gGameState;

void Ov025_PushCountersToEventFlags(void) {
    Ov025_UpdateDecimalDisplay(10, *(int *)(gGameState + 8), 0xf423f, 8, 0x14);
    Ov025_UpdateDecimalDisplay(0x14, *(int *)(gGameState + 0xc), 0xf423f, 8, 0x16);
}
