/* Return the address of the block embedded at +0x954c of the ov008 menu context (an interior
 * pointer, not a stored one). */

extern int data_ov008_02090f04[];
int Ov008_GetCtxBlock954c(void)
{
    return data_ov008_02090f04[1] + 0x954c;
}
