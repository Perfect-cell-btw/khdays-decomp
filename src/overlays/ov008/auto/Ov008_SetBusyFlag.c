/* Sets or clears the menu's busy bit (+0x28 bit 0). */

extern char *data_ov008_02090f00;

void Ov008_SetBusyFlag(int enabled)
{
    int bit;
    int flags;

    bit = enabled != 0 ? 1 : 0;

    bit = (unsigned char)bit;
    bit &= 1;
    flags = *(unsigned char *)(data_ov008_02090f00 + 0x28);
    flags &= ~1;
    *(unsigned char *)(data_ov008_02090f00 + 0x28) = flags | bit;
}
