int Ov022_IsByte2Zero(int p)
{
    return *(unsigned char *)(p + 2) == 0;
}
