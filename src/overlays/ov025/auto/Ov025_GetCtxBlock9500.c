/* Return the address of the block embedded at +0x9500 of the ov025 menu context. */

extern int data_ov025_020b5744;

int Ov025_GetCtxBlock9500(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x9500;
}
