struct b { unsigned char bit0 : 1; };
int Ov002_GetBit0OfByte0x2c(int p)
{
    return ((struct b *)(p + 0x2c))->bit0;
}
