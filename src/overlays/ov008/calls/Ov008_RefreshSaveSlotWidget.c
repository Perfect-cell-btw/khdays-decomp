/* Refresh one save slot's summary widget: if the slot has an accessor, build a two-word info
 * record { *accessor, summary } on the stack and hand it to the widget renderer. A slot with no
 * accessor is left alone.
 *
 * Parked as a "+4B frame-layout tie -- the ROM stores param_4 into the struct's 3rd word via the
 * prologue push {r3,r4,r5,lr}, the r3 push doubles as the store". It does not. `push {r3, ...}`
 * is mwcc's stack ALIGNMENT PADDING: r4, r5 and lr are three words, so it pushes a fourth
 * register to keep the frame 8-byte aligned, and r3 is simply the cheapest one to hand. Reading
 * that pushed r3 as data invented both a fourth parameter and a third array element; with the
 * record two words long and the function taking one argument, it matches exactly. */
extern int  Slot4_GetIfOccupied(int slot);
extern int  Ov008_GetEntryStatusByte(int slot);
extern void CopyToSlotTable8(short *info, int slot);

void Ov008_RefreshSaveSlotWidget(int slot) {
    int info[2];
    if (Slot4_GetIfOccupied(slot) != 0) {
        int summary = Ov008_GetEntryStatusByte(slot);
        info[0] = *(int *)Slot4_GetIfOccupied(slot);
        info[1] = summary;
        CopyToSlotTable8((short *)info, slot);
    }
}
