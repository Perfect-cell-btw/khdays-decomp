int Ov022_IndexedRecordAddr0x114(int p, int a)
{
    return a * 0x114 + *(int *)(*(int *)(p + 0x20) + 0xc) + 4;
}
