int Ov024_GetIndexedWordAt0x88(int p)
{
    int i = *(int *)(p + 0x90);
    return *(int *)(p + i * 4 + 0x88);
}
