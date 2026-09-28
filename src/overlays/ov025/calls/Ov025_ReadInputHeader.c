/* Reads the input header halfword of the screen work area. */

extern int data_ov025_020b5744;
extern int Mem_ReadU16();

int Ov025_ReadInputHeader(void) {
    return Mem_ReadU16(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x963e);
}
