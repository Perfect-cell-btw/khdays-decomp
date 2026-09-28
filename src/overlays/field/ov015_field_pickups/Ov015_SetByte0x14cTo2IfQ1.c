/* Sets a state byte of the object to 2 when the query's first byte is 1. */

void Ov015_SetByte0x14cTo2IfQ1(int p, int q)
{
    if (*(unsigned char *)q == 1)
        *(unsigned char *)(p + 0x14c) = 2;
}
