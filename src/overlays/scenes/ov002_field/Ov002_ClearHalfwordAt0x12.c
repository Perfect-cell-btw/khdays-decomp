/* Clears the halfword at +0x12. */

void Ov002_ClearHalfwordAt0x12(int p)
{
    *(unsigned short *)(p + 0x12) = 0;
}
