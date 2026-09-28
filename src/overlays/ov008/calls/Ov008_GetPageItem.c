/* Item index of page arg0, or NULL past its count. */

extern unsigned char *Ov008_GetPageTableEntry(int arg0);
extern char data_ov008_02090504[];

void *Ov008_GetPageItem(int arg0, int index)
{
    unsigned char *table = Ov008_GetPageTableEntry(arg0);

    if (index >= table[2]) {
        return 0;
    }

    return data_ov008_02090504 + (table + index)[3] * 4;
}
