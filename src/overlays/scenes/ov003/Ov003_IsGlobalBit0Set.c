/* Whether the A button is pressed. */

extern unsigned short gPadPressed;

int Ov003_IsGlobalBit0Set(void) {
    return (gPadPressed & 1) != 0;
}
