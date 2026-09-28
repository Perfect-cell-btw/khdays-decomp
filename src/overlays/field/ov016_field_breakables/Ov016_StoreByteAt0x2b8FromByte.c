/* Stores a byte at +0x2b8. */

void Ov016_StoreByteAt0x2b8FromByte(int p, int q)
{
    *(unsigned char *)(p + 0x2b8) = *(unsigned char *)q;
}
