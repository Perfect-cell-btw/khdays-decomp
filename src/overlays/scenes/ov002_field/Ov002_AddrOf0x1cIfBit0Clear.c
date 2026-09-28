struct b { unsigned char b0 : 1; };
int Ov002_AddrOf0x1cIfBit0Clear(int p)
{
    return ((struct b *)(p + 0x1b6))->b0 ? 0 : p + 0x1c;
}
