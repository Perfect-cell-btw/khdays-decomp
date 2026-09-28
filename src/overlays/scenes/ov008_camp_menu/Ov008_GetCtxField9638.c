/* Returns a halfword field of the camp-menu context (data_ov008_02090f04[1]). */

extern int data_ov008_02090f04[];
int Ov008_GetCtxField9638(void)
{
    return *(short *)(data_ov008_02090f04[1] + 0x9638);
}
