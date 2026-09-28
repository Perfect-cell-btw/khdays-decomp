/* Disable colour special effects: BLDCNT (0x04000050) = 0. */
void Ov011_ClearBlendA(void) {
    volatile unsigned short *reg_bldcnt = (volatile unsigned short *)0x04000050;
    *reg_bldcnt = 0;
}
