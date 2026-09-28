int Ov022_IsByte1Zero(int p)
{
    return *(unsigned char *)(p + 1) == 0;
}
