/* Returns a halfword field of the camp-menu context. */

extern int data_ov025_020b5744;

int Ov025_GetCtxField963a(void) {
    return *(signed short *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x963a);
}
