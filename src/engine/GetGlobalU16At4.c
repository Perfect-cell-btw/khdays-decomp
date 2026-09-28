/* ITCM getter: reads the u16 at offset 4 of the object pointed to by data_0204c228. */

extern int data_0204c228;

unsigned short GetGlobalU16At4(void) {
    return *(unsigned short *)(*(int *)&data_0204c228 + 4);
}
