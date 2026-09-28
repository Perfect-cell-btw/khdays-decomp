void Ov022_SetBit5OfHalf0IfByte2(int p)
{
    if (*(unsigned char *)(p + 2) != 0)
        *(unsigned short *)p |= 0x20;
}
