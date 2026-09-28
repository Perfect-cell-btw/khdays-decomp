/* Clears the shop's running totals. */

extern char *data_ov008_02090fac;

void Ov008_Shop_ClearTotals(void)
{
    *(int *)(data_ov008_02090fac + 0xc118) = 0;
    *(int *)(data_ov008_02090fac + 0xc11c) = 0;
}
