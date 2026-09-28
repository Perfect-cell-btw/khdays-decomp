/* Returns a field of the camp-menu context (data_ov008_02090f04[1]). */

extern int data_ov008_02090f04[];
int Ov008_GetCtxObject95c0(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x95c0);
}
