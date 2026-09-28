struct b2 { unsigned int b0 : 1, b1 : 1; };
void Ov107_SetBit1OfField0x40(int p, int flag)
{
    ((struct b2 *)(p + 0x40))->b1 = flag;
}
