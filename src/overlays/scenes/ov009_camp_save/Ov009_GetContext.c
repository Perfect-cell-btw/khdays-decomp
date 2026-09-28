/* Returns a word at a fixed offset of a global object. */

extern int data_ov009_020563e4;
int Ov009_GetContext(void) {
    return *(int *)((char *)&data_ov009_020563e4 + 4);
}
