/* Return the address of the +0x968c sub-block of the second ov009 global object. */
extern int data_ov009_020563e4;
int Ov009_GetCtxBlock968c(void) {
    return (&data_ov009_020563e4)[1] + 0x968c;
}
