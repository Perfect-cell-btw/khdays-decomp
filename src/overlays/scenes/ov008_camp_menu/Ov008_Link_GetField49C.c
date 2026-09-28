/* Returns the link context's word at +0x49c. */

extern char *data_ov008_02090f24;
int Ov008_Link_GetField49C(void)
{
    return *(int *)(data_ov008_02090f24 + 0x49c);
}
