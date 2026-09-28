/* Cancel the slot named by the index: nothing to do while
 * Ov002_Status_GetEntryWord reports it busy, otherwise release it as kind 3 and mark
 * the byte at +0x65 of the slot record 0xf. The context global is re-read for
 * that last store rather than cached -- that is the ROM. */
extern int Ov002_Status_GetEntryWord(int slot);
extern void Ov002_UploadSlotIconPalette(int slot, int kind);

extern char *data_ov002_0207f614;

void Ov002_CancelSlotByIndex(int index) {
    int slot = *(int *)(data_ov002_0207f614 + index * 4 + 0x220);

    if (Ov002_Status_GetEntryWord(slot) != 0) {
        return;
    }

    Ov002_UploadSlotIconPalette(slot, 3);
    *(unsigned char *)(data_ov002_0207f614 + slot + 0x65) = 0xf;
}
