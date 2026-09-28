int Ov016_AddrOf0x1cIfByte0x2bcClear(int p)
{
    return *(unsigned char *)(p + 0x2bc) != 0 ? 0 : p + 0x1c;
}
