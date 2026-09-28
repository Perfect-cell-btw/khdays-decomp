/* Returns a field of the camp-menu context (data_ov008_02090f04[1]). */

extern int data_ov008_02090f04[];
int Ov008_GetCtxField967c(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x967c);
}
