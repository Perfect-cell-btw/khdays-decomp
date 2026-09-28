/* Ov008_SetActivePage -- set the menu's active-page index and sync its control bits, ov008.
 * Writes the page index into the scene object: pushes it as a byte cursor position
 * (Ov008_SetFlagBit0 on obj+0x954c), updates the two page control bits at obj+0x4a80
 * (Ov008_SetControlBit1AtA7C / 02054e24), and stores the raw index at obj+0x9604. */
extern void Ov008_SetFlagBit0(int p, unsigned int v);
extern void Ov008_SetControlBit1AtA7C(int p, unsigned int v);
extern void Ov008_SetControlBit0AtA7C(int p, unsigned int v);
extern int  data_ov008_02090f04[];

void Ov008_SetActivePage(unsigned int page) {
    Ov008_SetFlagBit0(data_ov008_02090f04[1] + 0x954c, page);
    Ov008_SetControlBit1AtA7C(data_ov008_02090f04[1] + 0x4a80, page);
    Ov008_SetControlBit0AtA7C(data_ov008_02090f04[1] + 0x4a80, page);
    *(unsigned int *)(data_ov008_02090f04[1] + 0x9604) = page;
}
