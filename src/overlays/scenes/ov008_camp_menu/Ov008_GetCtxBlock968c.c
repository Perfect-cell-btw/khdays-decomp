/* Return the address of the +0x968c sub-block of the second ov008 global object. */

extern int data_ov008_02090f04[];
int Ov008_GetCtxBlock968c(void)
{
    return data_ov008_02090f04[1] + 0x968c;
}
