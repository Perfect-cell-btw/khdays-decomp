/* Return the address of the +0x968c sub-block of the second ov025 global object. */

extern int data_ov025_020b5744;

int Ov025_GetCtxBlock968c(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x968c;
}
