/* Returns the address of the indexed pool entry (0x114 bytes each) + 4. */

int Ov022_IndexedRecordAddr0x114(int p, int a)
{
    return a * 0x114 + *(int *)(*(int *)(p + 0x20) + 0xc) + 4;
}
