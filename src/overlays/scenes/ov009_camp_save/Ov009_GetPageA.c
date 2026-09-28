/* Read the word at +0x959c of the second ov009 global object. */
extern int data_ov009_020563e4;
int Ov009_GetPageA(void) {
    return *(int *)((&data_ov009_020563e4)[1] + 0x959c);
}
