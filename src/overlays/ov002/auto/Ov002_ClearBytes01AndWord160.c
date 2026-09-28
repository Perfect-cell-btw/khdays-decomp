void Ov002_ClearBytes01AndWord160(int p)
{
    *(char *)(p + 1) = 0;
    *(char *)(p + 0) = 0;
    *(int *)(p + 0x160) = 0;
}
