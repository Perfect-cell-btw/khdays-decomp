/* Set the word at +0x9614 of the second ov009 global object to 1. */
extern int data_ov009_020563e4;
void Ov009_SetCtxField9614(void) {
    *(int *)((&data_ov009_020563e4)[1] + 0x9614) = 1;
}
