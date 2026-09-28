/* Clears the slot bit of the current code in the menu state. */

extern char *data_ov008_02090f04[];
extern int Ov008_MapCodeToSlotIndex(void);

void Ov008_ClearSlotBit(void)
{
    int index = Ov008_MapCodeToSlotIndex();

    if (index != -1) {
        *(unsigned char *)(data_ov008_02090f04[1] + 0x963c) &= ~(1 << index);
    }
}
