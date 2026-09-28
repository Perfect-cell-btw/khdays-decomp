/* Returns the halfword at +0xc of the indexed message-database entry (0x14 bytes each). */

extern int data_0204c238;

int LoadArrayU16Stride14At0c(int index) {
    int base = *(int *)&data_0204c238;
    return *(unsigned short *)(base + index * 0x14 + 0xc);
}
