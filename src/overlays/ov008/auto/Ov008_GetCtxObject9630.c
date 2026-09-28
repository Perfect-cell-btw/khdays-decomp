/* Return the object pointer stored at +0x9630 of the ov008 menu context. */

extern int data_ov008_02090f04[];
int Ov008_GetCtxObject9630(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x9630);
}
