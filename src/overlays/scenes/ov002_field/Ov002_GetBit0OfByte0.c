/* Returns bit 0 of the first byte. */

int Ov002_GetBit0OfByte0(int p)
{
    return *(unsigned char *)p & 1;
}
