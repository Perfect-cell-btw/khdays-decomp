extern char *data_ov026_02091368;
extern void Slot_SetVisible(int handle, int cell, int visible);
extern void Slot_ForwardToEntry(int handle, int cell, unsigned short digit);

/* Draws a three-digit counter right-aligned, hiding the leading zeros. */
void Ov026_DrawThreeDigitCounter(unsigned int value, int *cells) {
    int handle = *(int *)(*(char **)&data_ov026_02091368 + 0xbfb4);
    int i;
    for (i = 2; i >= 0; i--) {
        if (i != 2 && value == 0) {
            Slot_SetVisible(handle, cells[i], 0);
        } else {
            Slot_SetVisible(handle, cells[i], 1);
            Slot_ForwardToEntry(handle, cells[i], (unsigned short)(value % 10));
        }
        value = value / 10;
    }
}
