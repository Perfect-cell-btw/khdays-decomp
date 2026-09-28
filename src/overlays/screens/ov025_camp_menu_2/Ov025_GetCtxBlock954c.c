/* Return the address of the block embedded at +0x954c of the ov025 menu context (an interior
 * pointer, not a stored one). */

extern int data_ov025_020b5744;

int Ov025_GetCtxBlock954c(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x954c;
}
