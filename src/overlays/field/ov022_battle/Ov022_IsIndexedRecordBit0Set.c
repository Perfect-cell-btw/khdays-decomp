/* Whether the indexed record (0x164 bytes each, from +0xda8) is in use and has bit 0 set. */

int Ov022_IsIndexedRecordBit0Set(int p, int i)
{
    int base = p + i * 0x164;
    if (*(signed char *)(base + 0xda9) == 0)
        return 0;
    return (*(unsigned char *)(base + 0xda8) & 1) != 0;
}
