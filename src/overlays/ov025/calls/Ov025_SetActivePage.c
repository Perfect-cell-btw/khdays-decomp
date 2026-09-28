/* Ov025_SetActivePage -- set the menu's active-page index and sync its control bits, ov008.
 * Writes the page index into the scene object: pushes it as a byte cursor position
 * (Ov025_SetFlagBit0 on obj+0x954c), updates the two page control bits at obj+0x4a80
 * (Ov025_SetControlBit1AtA7C / 02054e24), and stores the raw index at obj+0x9604. */
extern void Ov025_SetFlagBit0(int p, unsigned int v);
extern void Ov025_SetControlBit1AtA7C(int p, unsigned int v);
extern void Ov025_SetControlBit0AtA7C(int p, unsigned int v);
extern int  data_ov025_020b5744[];

void Ov025_SetActivePage(unsigned int page) {
    Ov025_SetFlagBit0(data_ov025_020b5744[1] + 0x954c, page);
    Ov025_SetControlBit1AtA7C(data_ov025_020b5744[1] + 0x4a80, page);
    Ov025_SetControlBit0AtA7C(data_ov025_020b5744[1] + 0x4a80, page);
    *(unsigned int *)(data_ov025_020b5744[1] + 0x9604) = page;
}
