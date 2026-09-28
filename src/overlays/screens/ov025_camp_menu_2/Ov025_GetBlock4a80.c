/* Return the address of the sub-block embedded at +0x4a80 of the ov025 menu context (an interior
 * pointer, not a stored pointer -- contrast Ov025_GetPageA, which loads one). */

extern int data_ov025_020b5744;

int Ov025_GetBlock4a80(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x4a80;
}
