int FX_Mul(int a, int b)
{
    return ((long long)a * b + 0x800) >> 12;
}
