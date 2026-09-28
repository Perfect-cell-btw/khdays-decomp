void SlotTable_SetMode(int *p, int v)
{
    p[(0x4000 + 0x624) / 4] = v;
}
