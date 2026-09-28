/* Return the word at +0x8b58 of the context at data_ov002_0207fa00. */

extern int data_ov002_0207fa00;

int Ov002_GetPhaseWord(void) {
    return *(int *)(*(int *)&data_ov002_0207fa00 + 0x8b58);
}
