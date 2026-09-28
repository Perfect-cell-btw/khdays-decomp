/* Ov008_PushCountersToEventFlags -- push the two menu counters into the event-flag store, ov008.
 * Writes the event context's counter fields (base+8 and base+0xc, base = *data_0204be18) into
 * flag groups 10 and 0x14 via Ov008_UpdateDecimalDisplay (width 8, max 0xf423f, sub-ids 0x14/0x16). */
extern void Ov008_UpdateDecimalDisplay(int group, int value, int max, int width, int subId);
extern int  data_0204be18;

void Ov008_PushCountersToEventFlags(void) {
    Ov008_UpdateDecimalDisplay(10, *(int *)(data_0204be18 + 8), 0xf423f, 8, 0x14);
    Ov008_UpdateDecimalDisplay(0x14, *(int *)(data_0204be18 + 0xc), 0xf423f, 8, 0x16);
}
