/* Whether the shop state is gone. */

extern char *data_ov008_02090fac;
int Ov008_Shop_IsClosed(void)
{
    return data_ov008_02090fac == 0;
}
