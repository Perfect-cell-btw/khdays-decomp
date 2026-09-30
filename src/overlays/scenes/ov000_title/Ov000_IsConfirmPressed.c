/* Report whether either of bits 0/3 of the shared status u16 is set. */
extern unsigned short gPadPressed;
int Ov000_IsConfirmPressed(void) {
    return (gPadPressed & 9) != 0;
}
