/* Resolve the argument to a slot index with Ov009_MapCodeToSlotIndex and set that slot's bit in the
 * mask byte at +0x963c of the ov009 menu context. A -1 (not found) result is ignored. */

extern char *data_ov009_020563e4[];
extern int Ov009_MapCodeToSlotIndex(void);

void Ov009_MarkSlotUsed(void)
{
    int index = Ov009_MapCodeToSlotIndex();

    if (index != -1) {
        *(unsigned char *)(data_ov009_020563e4[1] + 0x963c) |= 1 << index;
    }
}
