/* Sets the word at +0x110 to 0xc000 when bit 3 of the flags is set. */

void Ov022_SetWord0x110ToC000IfBit3(int p)
{
    if (*(unsigned char *)p & 8)
        *(int *)(p + 0x110) = 0xc000;
}
