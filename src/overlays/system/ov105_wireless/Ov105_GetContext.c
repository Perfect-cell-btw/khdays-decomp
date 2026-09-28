/* Returns a word at a fixed offset of a global object. */

extern int data_ov105_020bfa20;
int Ov105_GetContext(void) {
    return *(int *)((char *)&data_ov105_020bfa20 + 4);
}
