/* Writes the sub engine's BG1CNT (0x0400100a) from its fields, keeping the priority and mosaic
 * bits (0x43); the caller gives the extended-palette slot. */
void Bg_WriteSubBg1Cnt(int size, int colorMode, int screenBase, int charBase, int extPal) {
    volatile unsigned short *reg_bg1cnt_b = (volatile unsigned short *)0x0400100a;
    *reg_bg1cnt_b = *reg_bg1cnt_b & 0x43
        | (size << 0xe) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (extPal << 0xd);
}
