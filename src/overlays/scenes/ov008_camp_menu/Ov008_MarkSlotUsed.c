/* Resolve the argument to a slot index with Ov008_MapCodeToSlotIndex and set that slot's bit in the
 * mask byte at +0x963c of the ov008 menu context. A -1 (not found) result is ignored. */

extern char *data_ov008_02090f04[];
extern int Ov008_MapCodeToSlotIndex(void);

void Ov008_MarkSlotUsed(void)
{
    int index = Ov008_MapCodeToSlotIndex();

    if (index != -1) {
        *(unsigned char *)(data_ov008_02090f04[1] + 0x963c) |= 1 << index;
    }
}
