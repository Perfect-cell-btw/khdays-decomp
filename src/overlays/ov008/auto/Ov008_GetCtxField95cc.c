extern int data_ov008_02090f04[];
int Ov008_GetCtxField95cc(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x95cc);
}
