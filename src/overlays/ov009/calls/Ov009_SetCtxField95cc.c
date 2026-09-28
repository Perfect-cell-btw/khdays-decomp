/* Store a word at +0x95cc of the second ov009 global object. */
extern int data_ov009_020563e4;
void Ov009_SetCtxField95cc(int param_1) {
    *(int *)((&data_ov009_020563e4)[1] + 0x95cc) = param_1;
}
