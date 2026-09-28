/* Returns a word at a fixed offset of a global object. */

extern int data_ov105_020c04c0;
int Ov105_GetState(void) {
    return *(int *)((char *)&data_ov105_020c04c0 + 0x30);
}
