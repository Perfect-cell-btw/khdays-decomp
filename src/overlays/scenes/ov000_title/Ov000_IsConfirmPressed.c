/* Report whether either of bits 0/3 of the shared status u16 is set. */
extern unsigned short data_0204c190;
int Ov000_IsConfirmPressed(void) {
    return (data_0204c190 & 9) != 0;
}
