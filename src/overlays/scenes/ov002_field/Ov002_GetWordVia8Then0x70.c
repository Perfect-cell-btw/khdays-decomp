int Ov002_GetWordVia8Then0x70(int p)
{
    return *(int *)(*(int *)(p + 8) + 0x70);
}
