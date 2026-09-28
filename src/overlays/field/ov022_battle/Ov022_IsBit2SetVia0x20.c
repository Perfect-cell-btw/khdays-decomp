int Ov022_IsBit2SetVia0x20(int p)
{
    return (*(int *)(*(int *)(p + 0x20)) & 4) != 0;
}
