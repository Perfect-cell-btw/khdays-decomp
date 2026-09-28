/* Sets bit 0 of the flags at +0x1b6. */

struct bf { unsigned char b0 : 1; };
void Ov002_SetBit0OfByte0x1b6(int p)
{
    ((struct bf *)(p + 0x1b6))->b0 = 1;
}
