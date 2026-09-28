void Ov023_StorePairAt0x15b8(int p, int a, int b)
{
    *(int *)(p + 0x15b8) = a;
    *(int *)(p + 0x15bc) = b;
}
