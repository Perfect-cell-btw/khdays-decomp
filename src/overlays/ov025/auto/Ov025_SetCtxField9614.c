/* Set the word at +0x9614 of the second ov025 global object to 1. */

extern int data_ov025_020b5744;

void Ov025_SetCtxField9614(void) {
    *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9614) = 1;
}
