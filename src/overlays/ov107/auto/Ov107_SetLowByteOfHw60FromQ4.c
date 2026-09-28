void Ov107_SetLowByteOfHw60FromQ4(int p, int q)
{
    if (*(unsigned char *)(q + 2) != 0)
        return;
    *(unsigned short *)(p + 0x60) = (*(unsigned short *)(p + 0x60) & ~0xff) | *(unsigned char *)(q + 4);
}
