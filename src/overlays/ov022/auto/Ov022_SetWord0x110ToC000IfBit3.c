void Ov022_SetWord0x110ToC000IfBit3(int p)
{
    if (*(unsigned char *)p & 8)
        *(int *)(p + 0x110) = 0xc000;
}
