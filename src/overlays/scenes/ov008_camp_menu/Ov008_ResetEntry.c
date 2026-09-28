/* Resets an entry's slot tile (code 0). Returns the slot's tile buffer, or 0 when the code has no
 * slot. */

extern int Ov008_CodeToSlotTile(void *, int);
int Ov008_ResetEntry(void *arg0)
{
    return Ov008_CodeToSlotTile(arg0, 0);
}
