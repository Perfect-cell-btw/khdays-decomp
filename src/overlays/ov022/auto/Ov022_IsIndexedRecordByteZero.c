int Ov022_IsIndexedRecordByteZero(int p, int i)
{
    int base = *(int *)(p + 0x20);
    if (i < 0)
        return p;
    return *(unsigned char *)(*(int *)(base + 0xc) + i * 0x114) == 0;
}
