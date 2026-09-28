/* Return the signed halfword at +0x8ba8 of the context at data_ov002_0207fa00. */

extern int data_ov002_0207fa00;

int Ov002_GetStateWord(void) {
    return *(signed short *)(*(int *)&data_ov002_0207fa00 + 0x8ba8);
}
