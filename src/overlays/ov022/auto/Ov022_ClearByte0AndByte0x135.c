void Ov022_ClearByte0AndByte0x135(int p)
{
    *(char *)p = 0;
    *(char *)(p + 0x135) = 0;
}
