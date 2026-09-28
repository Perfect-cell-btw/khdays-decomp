/* Returns a word at a fixed offset of a global object. */

extern int data_ov025_020b574c;

int Ov025_GetContext_2(void) {
    return *(int *)((char *)&data_ov025_020b574c + 4);
}
