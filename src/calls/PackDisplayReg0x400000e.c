/* Set BG3CNT (0x0400000e), preserving priority + mosaic bits (0x43). */
void PackDisplayReg0x400000e(int size, int colorMode, int screenBase, int charBase)
{
    volatile unsigned short *reg_bg3cnt = (volatile unsigned short *)0x0400000e;
    unsigned short h = *reg_bg3cnt;
    *reg_bg3cnt = (h & 0x43) | (size << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2);
}
