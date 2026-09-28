/* Q12 fixed-point multiply: ((long long)a * b + 0x800) >> 12. The +0x800 is the round-to-nearest
 * bias for a 12-bit fraction. This is the SDK FX_Mul idiom the fixed-point vein depends on. */

int FX_Mul(int a, int b)
{
    return ((long long)a * b + 0x800) >> 12;
}
