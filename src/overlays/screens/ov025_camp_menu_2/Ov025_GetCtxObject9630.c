/* Return the object pointer stored at +0x9630 of the ov025 menu context. */

extern int data_ov025_020b5744;

int Ov025_GetCtxObject9630(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9630);
}
