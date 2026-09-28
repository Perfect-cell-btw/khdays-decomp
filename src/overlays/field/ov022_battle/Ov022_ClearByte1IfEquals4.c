/* Clears the byte at +1 when it is 4. */

void Ov022_ClearByte1IfEquals4(int p)
{
    if (*(unsigned char *)(p + 1) == 4)
        *(unsigned char *)(p + 1) = 0;
}
