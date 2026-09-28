void Ov002_SplitWordToHalves(int a, short *hi, short *lo)
{
    *hi = (short)(a >> 0x10);
    *lo = (short)a;
}
