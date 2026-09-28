void Ov015_SetByte0x14cTo2IfQ1(int p, int q)
{
    if (*(unsigned char *)q == 1)
        *(unsigned char *)(p + 0x14c) = 2;
}
