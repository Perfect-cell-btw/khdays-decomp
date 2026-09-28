/* Return the address of the block embedded at +0x9500 of the ov008 menu context. */

extern int data_ov008_02090f04[];
int Ov008_GetCtxBlock9500(void)
{
    return data_ov008_02090f04[1] + 0x9500;
}
