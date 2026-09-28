void Ov022_ClearByte1IfEquals4(int p)
{
    if (*(unsigned char *)(p + 1) == 4)
        *(unsigned char *)(p + 1) = 0;
}
