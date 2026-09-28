/* Read the word at +0x95cc of the second ov009 global object. */
extern int data_ov009_020563e4;
int Ov009_GetCtxField95cc(void) {
    return *(int *)((&data_ov009_020563e4)[1] + 0x95cc);
}
