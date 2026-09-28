/* Sets or clears bit 1 of the control word at +0x4a7c. */

struct dev { unsigned char _pad[0x4a7c]; unsigned int bit0 : 1, bit1 : 1; };
void Ov025_SetControlBit1AtA7C(int base, int flag)
{
    ((struct dev *)base)->bit1 = (flag != 0);
}
