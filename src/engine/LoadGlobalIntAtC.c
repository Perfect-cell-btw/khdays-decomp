/* Returns a word at a fixed offset of a global object. */

extern int data_0204bda4;

int LoadGlobalIntAtC(void) {
    return *(int *)((char *)&data_0204bda4 + 0xc);
}
