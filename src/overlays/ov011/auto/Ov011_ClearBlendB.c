/* Disable colour special effects on engine B: BLDCNT (0x04001050) = 0. */
void Ov011_ClearBlendB(void) {
    volatile unsigned short *reg_bldcnt_b = (volatile unsigned short *)0x04001050;
    *reg_bldcnt_b = 0;
}
