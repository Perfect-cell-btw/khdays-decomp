/* Resets an entry's slot tile (code 0). */

extern void Ov008_CodeToSlotTile(void *, int);
void Ov008_ResetEntry(void *arg0)
{
    Ov008_CodeToSlotTile(arg0, 0);
}
