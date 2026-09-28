/* Mission step 8: sets the mode (+0x94f4) to 9 when flag bit 2 of +0x955c is set. */

extern char *data_ov008_02090fa4;
void Ov008_MissionStep8SetModeIfFlagged(void)
{
    char *base = data_ov008_02090fa4;
    base += 0x9000;
    if (((unsigned int)*(int *)(base + 0x55c) << 29) >> 31) {
        *(int *)(base + 0x4f4) = 9;
    }
}
