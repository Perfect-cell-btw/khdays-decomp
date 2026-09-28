/* Ov008_ResetFourChannels -- reset the menu's four scroll/animation sub-objects, ov008.
 * Runs FreeFieldAt8 on each of the four animator blocks at base+0x9680/0x968c/0x9698/0x96a4. */
extern void FreeFieldAt8(int obj);
extern int  data_ov008_02090f04[];

void Ov008_ResetFourChannels(void) {
    FreeFieldAt8(data_ov008_02090f04[1] + 0x9680);
    FreeFieldAt8(data_ov008_02090f04[1] + 0x968c);
    FreeFieldAt8(data_ov008_02090f04[1] + 0x9698);
    FreeFieldAt8(data_ov008_02090f04[1] + 0x96a4);
}
