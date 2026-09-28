void Ov015_SetByte0x50To2IfQ1(int p, int q)
{
    if (*(unsigned char *)q == 1)
        *(unsigned char *)(p + 0x50) = 2;
}
