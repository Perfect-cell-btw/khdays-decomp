void Ov022_ClearBytes01(int p)
{
    *(char *)p = 0;
    *(char *)(p + 1) = 0;
}
