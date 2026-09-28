/* Store a word at +0x95cc of the second ov025 global object. */

extern int data_ov025_020b5744;

void Ov025_SetCtxField95cc(int arg0) {
    *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95cc) = arg0;
}
