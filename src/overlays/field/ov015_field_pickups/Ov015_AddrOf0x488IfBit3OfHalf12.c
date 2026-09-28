int Ov015_AddrOf0x488IfBit3OfHalf12(int p)
{
    return (*(unsigned short *)(p + 0x12) & 8) ? p + 0x488 : 0;
}
