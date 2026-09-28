/* Sets the eight halfwords at +0x2bd4 to -1. */

void Ov022_FillEightHalvesMinus1At0x2bd4(int p)
{
    int i;
    for (i = 0; i < 8; i++)
        ((short *)p)[i + 0x15ea] = -1;
}
