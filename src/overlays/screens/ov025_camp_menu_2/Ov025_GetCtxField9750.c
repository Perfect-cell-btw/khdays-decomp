/* Returns the menu state's byte at +0x9750. */

extern int data_ov025_020b5744;

int Ov025_GetCtxField9750(void) {
    return *(unsigned char *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9750);
}
