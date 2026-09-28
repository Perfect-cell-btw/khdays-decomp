/* Store the argument at +0x30 of the ov105 context unless the mode at +0x24 is 9 or 10 -- the ROM
 * spells that as the unsigned range test (mode - 9) > 1. */

/* Store param at +0x30 unless the +0x24 mode is 9 or 10. */
extern int data_ov105_020c04c0;
void Ov105_SetField30IfModeAllows(int param_1) {
    if ((unsigned int)((&data_ov105_020c04c0)[9] - 9) > 1) (&data_ov105_020c04c0)[12] = param_1;
}
