/* Marks the eight slot ids free (-1). */

void Ov084_FillEightHalvesMinus1(short *base)
{
    int i;
    for (i = 0; i < 8; i++)
        base[i + 0x88] = -1;
}
