struct b1 { unsigned int b0 : 1; };
void Ov107_SetBit0OfField0x40(int p, int flag)
{
    ((struct b1 *)(p + 0x40))->b0 = flag;
}
