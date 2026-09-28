extern int data_ov008_02090504[];
int *Ov008_GetItemTableEntry(unsigned int index)
{
    if (index >= 6) {
        return 0;
    }
    return &data_ov008_02090504[index];
}
