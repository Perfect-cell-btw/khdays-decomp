/* Returns the setup context's halfword at +0x4c (0 without a context). */

extern int data_ov022_020b2e78;
extern unsigned short Mem_ReadU16(unsigned short *arg0);
unsigned short func_ov022_02088cdc(void) {
    int p = ((int *)&data_ov022_020b2e78)[1];
    if (p != 0) return Mem_ReadU16((unsigned short *)(p + 0x4c));
    return 0;
}
