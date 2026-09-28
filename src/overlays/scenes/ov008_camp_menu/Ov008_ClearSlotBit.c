/* Clears the slot bit of the current code in the menu state. */

extern char *data_ov008_02090f04[];
extern int Ov008_MapCodeToSlotIndex(int);

void Ov008_ClearSlotBit(int arg0)
{
    int index = Ov008_MapCodeToSlotIndex(arg0);

    if (index != -1) {
        *(unsigned char *)(data_ov008_02090f04[1] + 0x963c) &= ~(1 << index);
    }
}
