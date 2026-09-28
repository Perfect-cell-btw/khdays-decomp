void Ov022_FillEightHalvesMinus1At0x2bd4(int p)
{
    int i;
    for (i = 0; i < 8; i++)
        ((short *)p)[i + 0x15ea] = -1;
}
